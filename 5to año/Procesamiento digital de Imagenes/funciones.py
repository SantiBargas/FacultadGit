import numpy as np
import cv2 as cv
from scipy.ndimage import generic_filter
from scipy.ndimage import median_filter
from numpy.fft import fft2, fftshift
from matplotlib import pyplot as plt
import statistics as stats
import math

### MOSTRAR IMAGENES E HISTOGRAMAS ###
# Mostrar histograma
def mostrar_histograma(img):
    plt.figure(figsize=(10, 5))
    plt.hist(img.ravel(), bins=256, range=[0, 256], color='gray')
    plt.title("Histograma de la Imagen")
    plt.xlabel("Intensidad de píxel")
    plt.ylabel("Frecuencia")
    plt.grid()
    return

# Mostrar imagen con opencv o matplotlib
def mostrar_imagen(img, titulo="Imagen", open_cv=True):
    if open_cv:
        cv.imshow(titulo, img)
    else:
        plt.figure(figsize=(10, 5))
        plt.imshow(img, cmap='gray')
        plt.title(titulo)
        plt.axis('off')
    return

# Mostrar espectro de Fourier
def mostrar_espectro_fourier(img, titulo="Espectro de Fourier", open_cv=True):
    F = fft2(img)
    F_shifted = fftshift(F)
    magnitude = np.abs(F_shifted)
    spectrum = np.log1p(magnitude)
    spectrum_norm = cv.normalize(spectrum, None, 0, 255, cv.NORM_MINMAX)
    spectrum_uint8 = spectrum_norm.astype(np.uint8)
    if open_cv:
        cv.imshow(titulo, spectrum_uint8)
    else:
        plt.figure(figsize=(10, 5))
        plt.imshow(spectrum, cmap='gray')
        plt.title(titulo)
        plt.axis('off')
        plt.colorbar()
    return spectrum_uint8

# Mostrar imagen junto a su espectro de Fourier
def mostrar_imagen_y_espectro(img, titulo_imagen="Imagen", titulo_espectro="Espectro de Fourier"):
    # 2. Calcular la transformada de Fourier
    f = np.fft.fft2(img)
    fshift = np.fft.fftshift(f)

    # 3. Calcular el espectro en escala logarítmica
    magnitude_spectrum = 20 * np.log1p(np.abs(fshift))  # log(1 + |F|)

    # 4. Normalizar para visualizar con OpenCV
    magnitude_spectrum_norm = cv.normalize(magnitude_spectrum, None, 0, 255, cv.NORM_MINMAX)
    magnitude_spectrum_uint8 = magnitude_spectrum_norm.astype(np.uint8)

    # 5. Concatenar lado a lado (ambas deben ser del mismo tipo y tamaño)
    combined = np.hstack((img, magnitude_spectrum_uint8))

    # 6. Mostrar con OpenCV
    cv.imshow('Imagen original (izq) y Espectro de Fourier (der)', combined)
    return

# Redimensionar imagen
'''
dst = cv2.resize(src, dsize[, dst[, fx[, fy[, interpolation]]]])

Parámetro	Tipo	Descripción
src	np.ndarray	Imagen de entrada (puede ser en escala de grises o color, cualquier dimensión válida).
dsize	(int, int)	Tamaño de salida deseado: (ancho, alto). Si se establece en (0, 0), se debe definir fx y fy.
dst (opcional)	np.ndarray	Imagen de salida (normalmente no se usa; la función devuelve la nueva imagen).
fx (opcional)	float	Factor de escala horizontal.
fy (opcional)	float	Factor de escala vertical.
interpolation (opcional)	int	Método de interpolación (ver más abajo).

Funcionamiento:
Si se especifica dsize, la imagen se redimensiona directamente a ese tamaño.
Si dsize = (0, 0), se debe indicar fx y/o fy, que escalan proporcionalmente a lo largo del eje x e y.
Si se especifican ambos (dsize y fx, fy), OpenCV ignora los factores fx y fy y utiliza solamente dsize.

Métodos de interpolación (interpolation):
Método	Constante de OpenCV	Descripción
Vecino más cercano	cv2.INTER_NEAREST	Rápido, pero menor calidad (cuadrado por píxel).
Interpolación bilineal	cv2.INTER_LINEAR	Buena calidad, por defecto al agrandar.
Interpolación bicúbica	cv2.INTER_CUBIC	Más suave que LINEAR, pero más lento.
Interpolación por área	cv2.INTER_AREA	Ideal para reducir imágenes.
Lanczos	cv2.INTER_LANCZOS4	Alta calidad, más lento, para ampliaciones precisas.
'''

### MANEJO DE INTERFZ ###
# Seleccionar n puntos de la imagen
def seleccionar_puntos(img, titulo="Imagen", color=(0, 0, 255), thickness=3):
    puntos = []

    img_hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    # Función que maneja los eventos del mouse
    def mouse_seleccionar_puntos(event, x, y, flags, param):
        if event == cv.EVENT_LBUTTONDOWN:
            puntos.append((x,y))
            print(img_hsv[y,x])

    cv.namedWindow(titulo + ": Seleccionar puntos")
    cv.setMouseCallback(titulo + ": Seleccionar puntos", mouse_seleccionar_puntos) 

    while True:
        # Dibujar los puntos si fueron seleccionados
        img_mostrar = img.copy() # cv.cvtColor(img.copy(), cv.COLOR_GRAY2BGR) #cv.resize(spectrum_uint8.copy(), (size, size), interpolation=cv.INTER_NEAREST)
        # SI ANDA MAL, SACAR LA CONVERSIÓN DE COLOR


        if (puntos is not None):
            for puntos_i in range(0,len(puntos)):
                cv.circle(img_mostrar, puntos[puntos_i], thickness, color, -1)

        cv.imshow(titulo + ": Seleccionar puntos", img_mostrar)

        key = cv.waitKey(1) & 0xFF
        # Presionar ENTER para salir
        if key == 13:
            cv.setMouseCallback(titulo + ": Seleccionar puntos", lambda *args : None)
            break
    return puntos

# Umbralizar
def umbralizar(img,titulo="Imagen"):

    if len(img.shape) == 3:
        img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    else:
        img_gray = img.copy()

    def nothing(x):
        pass

    # Crear ventana y trackbars
    cv.namedWindow(titulo + ': umbralizado')
    cv.createTrackbar('Umbral', titulo + ': umbralizado', 128, 255, nothing)
    
    while True:
        umbral = cv.getTrackbarPos('Umbral', titulo + ': umbralizado')
        _, img_umbralizada = cv.threshold(img_gray,umbral,255,cv.THRESH_BINARY)
        cv.imshow(titulo + ': umbralizado', img_umbralizada)

        key = cv.waitKey(100) & 0xFF
        if key == 13:  # Enter
            break

    return img_umbralizada

### PERFILES DE INTENSIDAD ###
def perfil_intensidad(img, x=None, y=None):
    if x is not None:
        # Perfil horizontal
        perfil = img[x, :]
        plt.figure(figsize=(10, 5))
        plt.plot(perfil, color='blue')
        plt.title(f"Perfil de Intensidad Horizontal en x={x}")
        plt.xlabel("Columna")
        plt.ylabel("Intensidad")
        plt.grid()
    elif y is not None:
        # Perfil vertical
        perfil = img[:, y]
        plt.figure(figsize=(10, 5))
        plt.plot(perfil, color='red')
        plt.title(f"Perfil de Intensidad Vertical en y={y}")
        plt.xlabel("Fila")
        plt.ylabel("Intensidad")
        plt.grid()
    else:
        raise ValueError("Debe proporcionar un valor para x o y.")
    return

### FILTROS FRECUENCIALES ###
def aplicar_filtro_frecuencial(F_shift, H):
    G = F_shift * H
    g = np.fft.ifft2(np.fft.ifftshift(G))
    g_real = np.real(g)
    g_norm = cv.normalize(g_real, None, 0, 255, cv.NORM_MINMAX).astype(np.uint8)
    return g_norm

# Convertir filtro de espacio a frecuencia
def filtro_espacio_a_frecuencia(h, img):
    # Crear filtro frecuencial del mismo tamaño que la imagen
    H_padded = np.zeros_like(img, dtype=np.float32)
    m, n = h.shape
    # Insertar el kernel en la esquina superior izquierda
    H_padded[:m, :n] = h
    # Centrar el kernel en la imagen
    H_padded = np.fft.ifftshift(H_padded)

    # Transformar a dominio frecuencia
    H = np.fft.fft2(H_padded)
    H = np.fft.fftshift(H)
    return H

# Filtro pasa-bajos ideal
def filtro_pasa_bajos_ideal(img, D0):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2)

    H = np.zeros((M, N), dtype=np.float32)
    H[D <= D0] = 1

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

def filtro_pasa_bajos_gaussiano(img, D0):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2) + 1e-8  # evitar división por cero

    H = np.exp(-(D**2) / (2 * (D0**2)))

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

def filtro_pasa_bajos_butterworth(img, D0, n=2):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2) + 1e-8  # evitar división por cero

    H = 1 / (1 + (D / D0)**(2 * n))

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

def filtro_pasa_altos_ideal(img, D0):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2)

    H = np.ones((M, N), dtype=np.float32)
    H[D <= D0] = 0

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

def filtro_pasa_altos_gaussiano(img, D0):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2) + 1e-8  # evitar división por cero

    H = 1 - np.exp(-(D**2) / (2 * (D0**2)))

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

def filtro_pasa_altos_butterworth(img, D0, n=2):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2) + 1e-8  # evitar división por cero

    H = 1 / (1 + (D0 / D)**(2 * n))

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back







### RUIDOS ###
# Aplicar ruido sal y pimienta
def ruido_sal_pimienta(img, p_salt=0.01, p_pepper=0.01):
    random_img = np.random.rand(*img.shape)
    img_salt_pepper = img.copy()
    color_salt = 255
    color_pepper = 0
    img_salt_pepper[random_img < p_salt] = color_salt
    img_salt_pepper[np.logical_and(random_img >= p_salt, random_img < p_salt + p_pepper)] = color_pepper
    return img_salt_pepper

# Aplicar ruido uniforme
def ruido_uniforme(img, color_A=0, color_B=5):
    ruido_uniforme = np.random.uniform(color_A, color_B, img.shape).astype(np.int16)
    img_uniform = np.clip(img.astype(np.int16) + ruido_uniforme, 0, 255).astype(np.uint8)
    return img_uniform

# Aplicar ruido gaussiano
# mu es media y sigma es desviación estándar
def ruido_gaussiano(img, color_mu=0, color_sigma=5):
    ruido_gaussiano = np.random.normal(color_mu, color_sigma, img.shape).astype(np.int16)
    img_gaussian = np.clip(img.astype(np.int16) + ruido_gaussiano, 0, 255).astype(np.uint8)
    return img_gaussian

# Aplicar ruido exponencial
def ruido_exponencial(img, lambd=0.1):
    a = lambd
    z = np.random.randn(*img.shape)
    ruido_exponencial = np.where(z >= 0, a * np.exp(-z * a), 0).astype(np.int16)
    img_exponential = np.clip(img.astype(np.int16) + ruido_exponencial, 0, 255).astype(np.uint8)
    return img_exponential

# Aplicar ruido impulsivo unimodal
def ruido_impulsivo_unimodal(img, p=0.01, color=255):
    random_img = np.random.rand(*img.shape)
    img_impulsive = img.copy()
    img_impulsive[random_img < p] = color
    return img_impulsive


### FILTROS DE MEDIAS ###
# Filtro de media geométrica
# Bueno para ruido gaussiano, falla con ruido impulsivo.
def filtro_media_geometrica(img, size=3):
    filtrada = generic_filter(img.astype(np.float32), stats.geometric_mean, size)
    return np.clip(filtrada, 0, 255).astype(np.uint8)

# Filtro de la media contra harmónica
# Bueno para ruido impulsivo
def filtro_media_contra_harmonica(img, size=3, Q=-1):
    def ch_mean(data):
        numerator = sum(x**(Q + 1) for x in data)
        denominator = sum(x**Q for x in data)
        if denominator == 0:
            return 0
        return numerator / denominator
    filtrada = generic_filter(img.astype(np.float32), ch_mean, size)
    return np.clip(filtrada, 0, 255).astype(np.uint8)

### FILTROS DE ORDEN ###
# Filtro de mediana
def filtro_mediana(img, size=3):
    filtrada = median_filter(img, size=size)
    return np.clip(filtrada, 0, 255).astype(np.uint8)

# Filtro de punto medio
# Util para ruido tipo gaussiano o uniforme
def filtro_punto_medio(img, size=3):
    def punto_medio(pixels):
        return 0.5 * (np.max(pixels) + np.min(pixels))
    filtrada = generic_filter(img.astype(np.float32), punto_medio, size)
    return np.clip(filtrada, 0, 255).astype(np.uint8)

# Filtro de media alfa recortado
# d es la cantidad de valores a descartar (deben ser pares)
def filtro_media_alfa_recortado(img, size=3, d=4):
    def media_alfa_recortado(pixels):
        sorted_pixels = np.sort(pixels)
        n = len(sorted_pixels)
        trim = d // 2
        if d >= n:
            return np.mean(sorted_pixels)  # fallback
        trimmed = sorted_pixels[trim : n - trim]
        return np.mean(trimmed)
    filtrada = generic_filter(img.astype(np.float32), media_alfa_recortado, size)
    return np.clip(filtrada, 0, 255).astype(np.uint8)

### CÓMPUTO DEL ECM ###
def ecm(img_A,img_B):
    err = np.sum((img_A.astype("float") - img_B.astype("float")) ** 2)
    err /= float(img_A.shape[0] * img_A.shape[1])
    return err

### FILTROS FRECUENCIALES ###
# Filtro rechazabanda ideal
# D0 es el radio del filtro y W es el ancho de la banda
def filtro_rechazabanda_ideal(img, D0, W, pasabanda=False):
    # Convertir a float32
    img_float = img.astype(np.float32)

    # FFT 2D
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    # Crear el filtro H(u,v)
    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2)

    H = np.ones((M, N), dtype=np.float32)
    H[(D >= D0 - W/2) & (D <= D0 + W/2)] = 0

    if (pasabanda):
        H = 1-H

    # Aplicar el filtro
    G = dft_shift * H

    # Inversa
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)

    # Normalizar a 0–255
    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

# Filtro rechazabanda gaussiano
# D0 es el radio del filtro y W es el ancho de la banda
def filtro_rechazabanda_gaussiano(img, D0, W, pasabanda=False):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    u = np.arange(M)
    v = np.arange(N)
    U, V = np.meshgrid(v - N//2, u - M//2)
    D = np.sqrt(U**2 + V**2) + 1e-8  # evitar división por cero

    # Filtro gaussiano rechazabanda
    H = 1 - np.exp(-((D**2 - D0**2)**2) / (D**2 * (W**2)))

    if (pasabanda):
        H = 1-H

    # Aplicar el filtro
    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    img_back = np.abs(img_back)
    img_back = np.clip(img_back, 0, 255).astype(np.uint8)
    return img_back

# Filtro notch ideal
def filtro_notch_ideal(img, notch_centers, D0, pasabanda=False):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    U, V = np.meshgrid(np.arange(N), np.arange(M))
    H = np.ones((M, N), dtype=np.float32)

    for u0, v0 in notch_centers:
        Dk = np.sqrt((U - u0)**2 + (V - v0)**2)
        Dk_conj = np.sqrt((U - (N - u0))**2 + (V - (M - v0))**2)
        H[Dk <= D0] = 0
        H[Dk_conj <= D0] = 0

    if (pasabanda):
        H = 1-H

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    return np.clip(np.abs(img_back), 0, 255).astype(np.uint8)

# Filtro notch gaussiano
def filtro_notch_gaussiano(img, notch_centers, D0, pasabanda=False):
    img_float = img.astype(np.float32)
    dft = np.fft.fft2(img_float)
    dft_shift = np.fft.fftshift(dft)

    M, N = img.shape
    U, V = np.meshgrid(np.arange(N), np.arange(M))
    H = np.ones((M, N), dtype=np.float32)

    for u0, v0 in notch_centers:
        Dk = np.sqrt((U - u0)**2 + (V - v0)**2)
        Dk_conj = np.sqrt((U - (N - u0))**2 + (V - (M - v0))**2)
        H *= (1 - np.exp(-(Dk**2) / (2 * D0**2)))
        H *= (1 - np.exp(-(Dk_conj**2) / (2 * D0**2)))

    if (pasabanda):
        H = 1-H

    G = dft_shift * H
    G_ishift = np.fft.ifftshift(G)
    img_back = np.fft.ifft2(G_ishift)
    return np.clip(np.abs(img_back), 0, 255).astype(np.uint8)


### DETECCIÓN DE BORDES ###
# Detección de Prewitt
# Muy sensible al ruido
def prewitt(img, threshold=100):
    # Convertir a escala de grises si es necesario
    if len(img.shape) == 3:
        gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    else:
        gray = img.copy()

    # Máscaras Prewitt
    kernel_x = np.array([[ -1, 0, 1],
                         [ -1, 0, 1],
                         [ -1, 0, 1]], dtype=np.float32)

    kernel_y = np.array([[ 1,  1,  1],
                         [ 0,  0,  0],
                         [-1, -1, -1]], dtype=np.float32)

    # Aplicar convoluciones
    grad_x = cv.filter2D(gray, -1, kernel_x)
    grad_y = cv.filter2D(gray, -1, kernel_y)

    # Magnitud del gradiente
    grad_mag = np.sqrt(grad_x.astype(np.float32)**2 + grad_y.astype(np.float32)**2)
    grad_mag = np.uint8(grad_mag)

    # Umbralizar para obtener bordes (imagen binaria)
    _, binary_edges = cv.threshold(grad_mag, threshold, 255, cv.THRESH_BINARY)

    return binary_edges

# Sobel
# Muy sensible al ruido
# dst = cv.Sobel(src, ddepth, dx, dy[, dst[, ksize[, scale[, delta[,borderType]]]]])
'''src	Imagen de entrada (debe ser en escala de grises o canal único).
ddepth	Profundidad de la imagen de salida (cv2.CV_64F, CV_32F, CV_16S, etc). Para evitar saturación, se suele usar cv2.CV_64F o CV_32F.
dx	Orden de la derivada en el eje X (horizontal).
dy	Orden de la derivada en el eje Y (vertical).
dst	(Opcional) Imagen de salida. Si no se da, se crea automáticamente.
ksize	Tamaño del kernel Sobel (debe ser impar: 1, 3, 5, 7). ksize=3 es lo más común.
scale	(Opcional) Factor de escala aplicado al gradiente calculado (por defecto 1).
delta	(Opcional) Valor agregado al resultado después de la convolución (por defecto 0).
borderType	Tipo de borde (cómo se extrapolan los píxeles al borde). Por ejemplo, cv2.BORDER_DEFAULT o cv2.BORDER_REFLECT.'''

# Laplaciano
'''
dst = cv2.Laplacian(src, ddepth[, dst[, ksize[, scale[, delta[, borderType]]]]])
src	Imagen de entrada (grayscale o 1 canal).
ddepth	Profundidad de la imagen de salida (por ejemplo, cv2.CV_64F para evitar pérdida por saturación).
dst	(Opcional) Imagen de salida. Si no se da, se crea internamente.
ksize	Tamaño del kernel de derivación. Valores típicos: 1, 3, 5, 7.
scale	(Opcional) Escala aplicada al resultado (por defecto 1).
delta	(Opcional) Se suma al resultado después del cálculo del Laplaciano.
borderType	Cómo se extrapolan los bordes (cv2.BORDER_DEFAULT es el más usado).
'''

# Canny

'''
edges = cv2.Canny(src, threshold1, threshold2[, edges[, apertureSize[, L2gradient]]])

src	Imagen de entrada en escala de grises (requisito).
threshold1	Umbral inferior para el gradiente (seguimiento por histéresis).
threshold2	Umbral superior para el gradiente.
edges	(Opcional) Imagen de salida.
apertureSize	Tamaño del kernel Sobel usado para encontrar gradiente. Comúnmente 3. Debe ser impar (1, 3, 5, 7).
L2gradient	Booleano: si True, usa gradiente exacto; si False, usa aproximado 

Relación sugerida:
    Elegí threshold2 = 2 × threshold1 (o incluso 3 × threshold1 como punto de partida).
Valores típicos:
    Imágenes con buen contraste: threshold1 = 50, threshold2 = 150
    Imágenes con bajo contraste: threshold1 = 30, threshold2 = 100
    Muy ruidosas: aplicá blur primero, luego threshold1 = 100, threshold2 = 200
'''

def canny_trackbar(img,titulo="Imagen"):
    # Callback vacío para la trackbar
    def nothing(x):
        pass

    # Crear ventana
    cv.namedWindow(titulo+' Canny')

    # Crear trackbar en la ventana
    # Parámetros: nombre, ventana, valor_inicial, valor_max, callback
    cv.createTrackbar('threshold1', titulo+' Canny', 50, 255, nothing)
    cv.createTrackbar('threshold2', titulo+' Canny', 150, 255, nothing)

    if img.dtype != 'uint8':
        img = cv.normalize(img, None, 0, 255, cv.NORM_MINMAX)
        img = img.astype('uint8')

    if len(img.shape) == 3:
        img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    else:
        img_gray = img.copy()


    while True:
        threshold1 = cv.getTrackbarPos('threshold1', titulo+' Canny')
        threshold2 = cv.getTrackbarPos('threshold2', titulo+' Canny')

        # Aplicar Canny
        img_bordes = cv.Canny(img_gray,threshold1,threshold2)
        cv.imshow(titulo+' Canny',img_bordes)

        # Salir con ' enter'
        if cv.waitKey(100) & 0xFF == 13:
            break

    return img_bordes

# Hough clásica
## Detecta líneas infinitas en una imagen binaria
## Retorna los parámetros en forma polar: rho y theta
'''
lines = cv2.HoughLines(src, rho, theta, threshold)
src	Imagen binaria (como la salida de Canny).
rho	Resolución en píxeles del parámetro ρ (ej: 1).
theta	Resolución angular en radianes (ej: np.pi/180).
threshold	Cantidad mínima de votos para que se considere una línea.
lines	(Salida) Lista de líneas detectadas en forma (rho, theta).
'''

def polar_a_cartesiana(img,line):
    centro = (img.shape[0]/2,img.shape[1]/2)
    theta = line[1]
    rho = line[0]
    x = rho * math.cos(theta) + centro
    y = rho * math.sin(theta) + centro
    return [x,y]

# Dibujar hough detectada
def dibujar_hough(img, lines, probabilistico=True, thickness=3):
    img_hough = img.copy()
    colors = [(0,0,255), (0,255,255), (0,255,0), (255,255,0), (255,0,0), (255,0,255)]
    
    if lines is None:
        return img_hough

    if probabilistico:
        for i in range(len(lines)):
            color = colors[i % len(colors)]
            x1, y1, x2, y2 = lines[i][0]
            pt_A = (x1, y1)
            pt_B = (x2, y2)
            cv.line(img_hough, pt_A, pt_B, color, thickness)
    else:
        h, w = img.shape[:2]
        for i in range(len(lines)):
            color = colors[i % len(colors)]
            rho, theta = lines[i][0]

            # Conversión de (rho, theta) a dos puntos cartesianas
            a = np.cos(theta)
            b = np.sin(theta)
            x0 = a * rho
            y0 = b * rho

            # Dos puntos suficientemente alejados para dibujar la línea
            x1 = int(x0 + 1000 * (-b))
            y1 = int(y0 + 1000 * (a))
            x2 = int(x0 - 1000 * (-b))
            y2 = int(y0 - 1000 * (a))

            cv.line(img_hough, (x1, y1), (x2, y2), color, thickness)

    return img_hough

# Hough probabilística.
## Es una versión optimizada y más práctica que detecta segmentos de línea en lugar de líneas infinitas.
## Esto la hace más útil para detectar líneas reales en imágenes (como bordes de objetos).
## Devuelve líneas en formato: [[x1, y1, x2, y2]].
'''
lines = cv2.HoughLinesP(src, rho, theta, threshold, minLineLength, maxLineGap)
minLineLength	Longitud mínima que debe tener un segmento para ser aceptado.
maxLineGap	Máxima separación entre puntos consecutivos de una línea para unirlos.
'''

def hough_trackbar(img,img_bordes,titulo="Imagen"):

    # Callback vacío para la trackbar
    def nothing(x):
        pass
    # Crear ventana
    cv.namedWindow(titulo+' Hough')

    # Crear trackbar en la ventana
    # Parámetros: nombre, ventana, valor_inicial, valor_max, callback
    cv.createTrackbar('Threshold', titulo+' Hough', 50, 255, nothing)
    cv.createTrackbar('minLineLength', titulo+' Hough', 20, 255, nothing)
    cv.createTrackbar('maxLineGap', titulo+' Hough', 10, 255, nothing)
    cv.createTrackbar('thickness', titulo+' Hough', 1, 10, nothing)
    cv.createTrackbar('probabilistico', titulo+' Hough', 1, 1, nothing)

    while True:
        threshold = cv.getTrackbarPos('Threshold', titulo+' Hough')
        minLineLength = cv.getTrackbarPos('minLineLength', titulo+' Hough')
        maxLineGap = cv.getTrackbarPos('maxLineGap', titulo+' Hough')
        thickness = cv.getTrackbarPos('thickness', titulo+' Hough')
        prob_int = cv.getTrackbarPos('probabilistico', titulo+' Hough')

        probabilistico = bool(prob_int)

        # Aplicar Hough
        if probabilistico:
            lines = cv.HoughLinesP(img_bordes, rho=1, theta=np.pi/180, threshold=threshold, minLineLength=minLineLength,maxLineGap=maxLineGap)
        else:
            lines = cv.HoughLines(img_bordes, rho=1, theta=np.pi/180, threshold=threshold)
        
        img_hough = dibujar_hough(img=img,lines=lines,thickness=thickness,probabilistico=probabilistico)

        mostrar_imagen(img_hough, titulo+' Hough')

        # Salir con 'ENTER'
        if cv.waitKey(100) & 0xFF == 13:
            break

    return lines

# Hough círculos
## Retorna una matriz de círculos detectados, o None si no se encontró ninguno.
## Cada círculo tiene 3 valores: x, y, r → coordenadas del centro y radio del círculo
'''
circles = cv2.HoughCircles(src, method, dp, minDist[, circles[, param1[, param2[, minRadius[, maxRadius]]]]])

src	Imagen de entrada en escala de grises. Debe estar preprocesada (suavizada).
method	Siempre cv2.HOUGH_GRADIENT (único método disponible actualmente).
dp	Inverso de la resolución del acumulador. dp=1 usa la misma resolución que la imagen, dp=2 usa la mitad, etc.
minDist	Distancia mínima entre centros detectados (para evitar detecciones múltiples del mismo círculo).
param1	Umbral superior del Canny interno usado para la detección de bordes.
param2	Umbral del acumulador de centros: cuanto menor, más círculos detecta (pero más falsos positivos).
minRadius	Radio mínimo de los círculos a detectar.
maxRadius	Radio máximo de los círculos a detectar.
'''

# Componentes conectados
## Detecta componentes conectados (agrupaciones de píxeles blancos conectados entre sí) en una imagen binaria y les asigna una etiqueta única.
'''
retval, labels = cv2.connectedComponents(src[, labels[, connectivity[, ltype]]])

src	Imagen binaria de entrada (tipo uint8). Los píxeles diferentes de 0 se consideran foreground.
labels	(Opcional) Salida preasignada. Podés ignorarlo.
connectivity	Conectividad: 4 u 8. Define si los píxeles son vecinos por lados (4) o también por diagonales (8).
ltype	Tipo de dato de salida (usualmente cv2.CV_32S).
'''
#Retorna
#retval: número de componentes conectados encontrados (incluye el fondo como etiqueta 0).
#labels: una imagen del mismo tamaño que src, donde cada píxel tiene un número entero que indica a qué componente pertenece


'''
num_labels, labels, stats, centroids = cv.connectedComponentsWithStats(image[, connectivity[, ltype]])

image	Imagen binaria de entrada (uint8), fondo = 0, objetos ≠ 0
connectivity	4 o 8 — define qué es "conectado". 4-conectividad (por lados) o 8-conectividad (por lados y diagonales)
ltype	Tipo de datos de salida (cv.CV_32S por defecto). No suele ser necesario cambiarl
num_labels	Número total de componentes detectados (incluye el fondo como 0)
labels	Imagen de etiquetas con mismo tamaño que image. Cada píxel tiene el número de su componente (0 = fondo, 1, 2, 3, ...)
stats	Matriz num_labels × 5 con estadísticas de cada componente. Cada fila contiene:

left: coordenada x del borde izquierdo del bounding box
top: coordenada y del borde superior
width: ancho del bounding box
height: alto del bounding box
area: cantidad de píxeles del componente

centroids | Matriz num_labels × 2, con el centroide (x, y) de cada componente |
'''

### SEGMENTACIÓN ###
# Segmentación mediante crecimiento de regiones

def segmentacion_semillas(img_hsv, seeds, img_mask, P_min, P_max):
    alto, ancho = img_hsv.shape[:2]
    stack = list(seeds)  # Inicializamos con todas las semillas

    while stack:
        x, y = stack.pop()

        # Validar que esté dentro de los límites y sin marcar
        if x < 0 or x >= ancho or y < 0 or y >= alto:
            continue
        if img_mask[y, x] != 0:
            continue

        pixel = img_hsv[y, x]
        if cv.inRange(np.uint8([[pixel]]), P_min, P_max)[0, 0] == 255:
            img_mask[y, x] = 1

            # Agregar vecinos 4-conectados
            stack.extend([
                (x + 1, y),
                (x - 1, y),
                (x, y + 1),
                (x, y - 1)
            ])

    return img_mask

def pintar_imagen_con_mask(img, img_tag, img_bin=False):
    img_mostrar = img.copy()
    if (img_bin):
        img_mostrar = cv.cvtColor(img_mostrar, cv.COLOR_GRAY2BGR)
    
    mask = img_tag.astype(bool)
    img_mostrar[mask] = [0, 0, 255]
    return img_mostrar

def desaturar_imagen_con_mask(img_hsv, img_mask):
    img_mostrar = img_hsv.copy()
    mask = img_mask.astype(bool)
    img_mostrar[:,:,1] = 0
    img_mostrar[mask] = img_hsv[mask].copy()
    return cv.cvtColor(img_mostrar, cv.COLOR_HSV2BGR)

def segmentacion_semillas_UI(img, titulo="Imagen"):
    # Seleccionar puntos semilla
    seeds = seleccionar_puntos(img, thickness=2)
    img_hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    def nothing(x):
        pass

    # Crear ventana y trackbars
    cv.namedWindow(titulo + ': Segmentación')
    cv.createTrackbar('radioH', titulo + ': Segmentación', 10, 127, nothing)
    cv.createTrackbar('radioS', titulo + ': Segmentación', 40, 89, nothing)
    cv.createTrackbar('radioV', titulo + ': Segmentación', 40, 127, nothing)

    img_mostrar = img.copy()

    while True:
        radio_H = cv.getTrackbarPos('radioH', titulo + ': Segmentación')
        radio_S = cv.getTrackbarPos('radioS', titulo + ': Segmentación')
        radio_V = cv.getTrackbarPos('radioV', titulo + ': Segmentación')

        # Mostrar imagen original (o la última segmentada)
        cv.imshow(titulo + ': Segmentación', img_mostrar)

        key = cv.waitKey(100) & 0xFF
        if key == 13:  # Enter
            break
        elif key == 27:  # ESC
            return

    # Semilla principal (tomamos la primera)
    x, y = seeds[0]
    hsv = img_hsv[y, x]
    P = np.array([radio_H, radio_S, radio_V])

    P_min = np.clip(hsv - P, 0, [179, 255, 255])
    P_max = np.clip(hsv + P, 0, [179, 255, 255])

    # Segmentación
    img_mask = np.zeros(img_hsv.shape[:2], dtype=np.uint8)
    img_mask = segmentacion_semillas(img_hsv, seeds, img_mask, P_min, P_max)

    # Mostrar resultado
    img_mostrar = pintar_imagen_con_mask(img, img_mask)
    cv.imshow(titulo + ': Segmentacion', img_mostrar)
    cv.waitKey(0)


def segmentacion_color(img, seeds, titulo="Imagen"):
    img_hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    def nothing(x):
        pass

    # Crear ventana y trackbars
    cv.namedWindow(titulo + ': Segmentacion')
    cv.createTrackbar('radioH', titulo + ': Segmentacion', 10, 179, nothing)
    cv.createTrackbar('radioS', titulo + ': Segmentacion', 40, 255, nothing)
    cv.createTrackbar('radioV', titulo + ': Segmentacion', 40, 255, nothing)

    img_mostrar = img.copy()

    while True:
        radio_H = cv.getTrackbarPos('radioH', titulo + ': Segmentacion')
        radio_S = cv.getTrackbarPos('radioS', titulo + ': Segmentacion')
        radio_V = cv.getTrackbarPos('radioV', titulo + ': Segmentacion')

        # Mostrar imagen original (o la última segmentada)
        cv.imshow(titulo + ': Segmentacion', img_mostrar)

        # Semilla principal (tomamos la primera)
        x, y = seeds[0]
        hsv = img_hsv[y, x]
        P = np.array([radio_H, radio_S, radio_V])

        P_min = np.clip(hsv - P, 0, [179, 255, 255])
        P_max = np.clip(hsv + P, 0, [179, 255, 255])

        img_mask = cv.inRange(img_hsv,P_min,P_max)
        img_mostrar = desaturar_imagen_con_mask(img_hsv, img_mask)
        
        cv.imshow(titulo + ': Segmentacion', img_mostrar)

        key = cv.waitKey(100) & 0xFF
        if key == 13:  # Enter
            break
    
    return img_mask

def dibujar_centroides_stats(img, centroids):
    img_mostrar = img.copy()

    for i in range(1, len(centroids)):  # saltar fondo si corresponde
        cx, cy = centroids[i]
        cx, cy = int(cx), int(cy)
        color = tuple(int(c) for c in 255 - img[cy, cx])
        cv.circle(img_mostrar, (cx, cy), 5, color, -1)  # círculo rojo relleno

    cv.imshow("Centroides", img_mostrar)
    cv.waitKey(0)
    cv.destroyAllWindows()

### MORFOLOGÍA ###
# cv.getStructuringElement
'''
dst = cv.getStructuringElement(shape, ksize[, anchor])

shape: tipo de elemento estructurante:
    cv.MORPH_RECT: rectangular
    cv.MORPH_ELLIPSE: elíptico
    cv.MORPH_CROSS: forma de cruz

ksize: tamaño del kernel (ancho, alto), una tupla como (5, 5)
→ debe ser impar y positivo

anchor (opcional): punto de anclaje dentro del kernel.
Por defecto es el centro: (-1, -1)

Devuelve una matriz (np.ndarray) de tipo uint8 con 1s y 0s que representa el kernel.
'''

# cv.erode
'''
dst = cv.erode(src, kernel[, dst[, anchor[, iterations[, borderType[, borderValue]]]]])

Parámetros:
src: imagen de entrada (binaria o en escala de grises).
kernel: elemento estructurante (obtenido con cv.getStructuringElement()).
dst (opcional): imagen de salida (generalmente se omite, se devuelve directamente).
anchor (opcional): punto de anclaje del kernel; por defecto (-1, -1) (centro).
iterations (opcional): cuántas veces aplicar la erosión. Default es 1.
borderType (opcional): tipo de borde (cv.BORDER_CONSTANT, etc).
borderValue (opcional): valor de borde si borderType es BORDER_CONSTANT.

Retorna una nueva imagen (dst) donde se ha aplicado la erosión.
'''

# cv.dilate
'''
dst = cv.dilate(src, kernel[, dst[, anchor[, iterations[, borderType[, borderValue]]]]])

Parámetros:
src: imagen de entrada (binaria o en escala de grises).
kernel: elemento estructurante (normalmente creado con cv.getStructuringElement()).
dst (opcional): imagen de salida (se puede omitir).
anchor (opcional): punto de anclaje del kernel (por defecto (-1,-1) = centro).
iterations (opcional): número de veces que se aplica la dilatación (por defecto 1).
borderType (opcional): tipo de borde (por ejemplo, cv.BORDER_CONSTANT).
borderValue (opcional): valor de borde si el borderType es BORDER_CONSTANT.

Retorna una nueva imagen (dst) donde se ha aplicado la dilatación.
'''

# cv.morphologyEx
'''
dst = cv.morphologyEx(src, op, kernel[, dst[, anchor[, iterations[, borderType[, borderValue]]]]])

src: Imagen de entrada.
op: Tipo de operación morfológica a aplicar (ver más abajo).
kernel: Elemento estructurante (generalmente se usa cv.getStructuringElement()).
dst: Imagen de salida (opcional).
anchor: Punto de anclaje del kernel (por defecto, centro).
iterations: Número de veces que se aplica la operación (por defecto 1).
borderType / borderValue: Opciones para el tratamiento de los bordes (opcional).

Operaciones disponibles (op)
Código              Nombre	                ¿Qué hace?
cv.MORPH_ERODE	    Erosión	                Reduce zonas blancas
cv.MORPH_DILATE	    Dilatación	            Expande zonas blancas
cv.MORPH_OPEN	    Apertura                (Erosión → Dilatación)	Elimina ruido pequeño (puntos blancos aislados)
cv.MORPH_CLOSE	    Clausura                (Dilatación → Erosión)	Rellena huecos pequeños dentro de objetos
cv.MORPH_GRADIENT	Gradiente morfológico	Borde de los objetos (Dilatación - Erosión)
cv.MORPH_TOPHAT	    Top Hat	                src - apertura, resalta detalles más pequeños que el kernel (manchas brillantes)
cv.MORPH_BLACKHAT	Black Hat	            clausura - src, resalta manchas oscuras
cv.MORPH_HITMISS	Hit or Miss	            Detecta configuraciones específicas (sólo en imágenes binarias)
'''

# Obtener elemento estructurante a partir de píxel de imagen
def get_elemento_estructurante_from_img(img_bin,pixel):

    img_bgr = cv.cvtColor(img_bin, cv.COLOR_GRAY2BGR)
    img_hsv = cv.cvtColor(img_bgr, cv.COLOR_BGR2HSV)

    img_mask = np.zeros(img_hsv.shape[:2], dtype=np.uint8)
    img_ee = segmentacion_semillas(img_hsv, [pixel], img_mask, np.array([0,0,0]), np.array([10,10,10]))

    return img_ee

# Recortar mascara para quedarse con el bounding box
def recortar_mascara(mask):
    # Encontrar coordenadas donde la máscara es distinta de 0
    coords = cv.findNonZero(mask.astype(np.uint8))
    if coords is None:
        return None  # No hay píxeles activos

    # Calcular el bounding box
    x, y, w, h = cv.boundingRect(coords)

    # Recortar la región de interés
    recorte = mask[y:y+h, x:x+w]
    return recorte

def rotar_imagen(img,grados=0):
    (h, w) = img.shape[:2]
    centro = (w // 2, h // 2)
    M = cv.getRotationMatrix2D(centro, grados, 1.0)  # grados, escala 1.0
    return cv.warpAffine(img, M, (w, h))