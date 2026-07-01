import cv2
import numpy as np
import matplotlib.pyplot as plt

# Cargar una de tus imágenes (usaremos la 1 por defecto)
img = cv2.imread('imagen1.jpg')

if img is None:
    print("Error: No se pudo cargar la imagen.")
else:
    # Para trabajar con intensidad -> convertimos a escalas de grises 
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 

    # 1. Informe valores de intensidad de puntos particulares
    # Elegimos tres puntos: esquina, centro y un punto aleatorio
    h, w = gray.shape
    puntos = [(10, 10), (h // 2, w // 2), (h - 10, w - 10)]
    
    print("--- 1. Valores de Intensidad ---")
    for y, x in puntos:
        intensidad = gray[y, x]
        print(f"Punto (y={y}, x={x}): Intensidad = {intensidad}")

    # 2. Perfil de intensidad sobre una fila o columna
    # tomamos fila que pasa por el centro de la imagen
    fila_idx = h // 2
    perfil_fila = gray[fila_idx, :] # Extraemos toda la fila

    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(perfil_fila)
    plt.title(f"Perfil de Intensidad - Fila {fila_idx}")
    plt.xlabel("Columna (X)")
    plt.ylabel("Intensidad (0-255)")

    # 3. Perfil de intensidad para un segmento de interés cualquiera
    # Definimos un segmento desde (y0, x0) hasta (y1, x1)
    p0, p1 = (50, 50), (h - 50, w - 50)
    
    # Cantidad de puntos a muestrear en el segmento
    num_puntos = 200
    # Generamos las coordenadas del segmento
    perfil_x = np.linspace(p0[1], p1[1], num_puntos).astype(int)
    perfil_y = np.linspace(p0[0], p1[0], num_puntos).astype(int)
    
    # Extraemos los valores de intensidad a lo largo de esas coordenadas
    intensidad_segmento = gray[perfil_y, perfil_x]

    plt.subplot(1, 2, 2)
    plt.plot(intensidad_segmento, color='red')
    plt.title("Perfil de Segmento Diagonal")
    plt.xlabel("Punto en el segmento")
    plt.ylabel("Intensidad")

    # Mostrar la imagen original con la fila y el segmento marcados
    plt.figure()
    plt.imshow(gray, cmap='gray')
    plt.axhline(fila_idx, color='blue', linestyle='--', label='Fila central')
    plt.plot([p0[1], p1[1]], [p0[0], p1[0]], color='red', label='Segmento')
    plt.title("Líneas de Perfiles de Intensidad")
    plt.legend()
    
    plt.show() 

cv2.destroyAllWindows()