import cv2
import numpy as np
import matplotlib.pyplot as plt

# ==========================================
# 1. Transformaciones Lineales
# ==========================================
def generar_lut_lineal(a, c):
    """Genera la Look-Up Table para la transformación s = a*r + c"""
    r = np.arange(256) # Valores de entrada de 0 a 255
    s = a * r + c
    # Recortar valores fuera del rango [0, 255] y convertir a uint8
    s_recortado = np.clip(s, 0, 255).astype(np.uint8)
    return s_recortado

def aplicar_lut(imagen, lut):
    """Aplica la LUT a una imagen usando OpenCV."""
    return cv2.LUT(imagen, lut)

# ==========================================
# 3. Negativo de la imagen
# ==========================================
def generar_lut_negativo():
    return generar_lut_lineal(-1,255)

# ==========================================
# 4. Transformaciones por tramos
# ==========================================
def generar_lut_tramos(puntos_x,puntos_y):
    r = np.arange(256)
    s = np.interp(r,puntos_x,puntos_y)
    return np.clip(s,0,255).astype(np.uint8)

def mostrar_resultados(imagen_original, lut, imagen_procesada, titulo="Resultados"):
    """Muestra la imagen original, la curva de la LUT y la imagen procesada."""
    plt.figure(figsize=(12, 4))
    plt.suptitle(titulo, fontsize=14)
    
    # Subplot 1: Imagen Original
    plt.subplot(1, 3, 1)
    plt.imshow(imagen_original, cmap='gray', vmin=0, vmax=255)
    plt.title("Imagen Original")
    plt.axis('off')
    
    # Subplot 2: El mapeo (la curva de la LUT)
    plt.subplot(1, 3, 2)
    plt.plot(lut, color='blue')
    plt.title("Mapeo Aplicado (LUT)")
    plt.xlabel("Entrada (r)")
    plt.ylabel("Salida (s)")
    plt.grid(True)
    plt.xlim([0, 255])
    plt.ylim([0, 255])
    
    # Subplot 3: Imagen Resultante
    plt.subplot(1, 3, 3)
    plt.imshow(imagen_procesada, cmap='gray', vmin=0, vmax=255)
    plt.title("Imagen Obtenida")
    plt.axis('off')
    
    # Ajustar el espaciado y mostrar la ventana
    plt.tight_layout()
    plt.show()

# ==========================================
# BLOQUE PRINCIPAL (Pruebas)
# ==========================================
if __name__ == "__main__":

    rutas_imagenes = [
        '../../imagenes/building.jpg'
       # '../../imagenes/rmn.jpg',   
       # '../../imagenes/earth.bmp'  
    ]

    pruebas_ac = [
        (1.0, 80, "Solo aumento de brillo"),
        (2.0, 0, "Aumento de contraste"),
        (0.5, 50, "Disminución de contraste + brillo"),
        (-1.0, 255, "Negativo de la imagen") # ¡Esto ya te resuelve el inciso 3!
    ]
    
    for ruta in rutas_imagenes:
        img = cv2.imread(ruta, 0) 
        
        if img is None:
            print(f"Error: No se pudo cargar la imagen {ruta}. Saltando a la siguiente...")
            continue # Salta a la siguiente iteración si no encuentra la imagen
            
        for a_test, c_test, descripcion in pruebas_ac:
            
            # Generar la LUT
            lut_actual = generar_lut_lineal(a_test, c_test)
            
            # Aplicar la LUT a la imagen original
            img_res = cv2.LUT(img, lut_actual)
            
            # Mostrar todo. El programa pausará aquí hasta que cierres la ventana de matplotlib
            titulo_ventana = f"{descripcion} (a={a_test}, c={c_test}) - {ruta.split('/')[-1]}"
            mostrar_resultados(img, lut_actual, img_res, titulo_ventana)

   
    lut_neg = generar_lut_negativo()
    img_res_neg = aplicar_lut(img, lut_neg)
    mostrar_resultados(img, lut_neg, img_res_neg, "Negativo de la Imagen")

    
    x_coords = [0, 80,  180, 255]
    y_coords = [0, 30,  220, 255]
    lut_tramos = generar_lut_tramos(x_coords, y_coords)
    img_res_tramos = aplicar_lut(img, lut_tramos)
    mostrar_resultados(img, lut_tramos, img_res_tramos, "Compresión/Estiramiento por Tramos")