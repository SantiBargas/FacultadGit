import cv2
import matplotlib.pyplot as plt
import numpy as np

# RUTAS MANUALES (Funcionan si ejecutas DESDE la carpeta 'Practica')
img1 = '../../imagenes/patron.tif'
img2 = '../../imagenes/patron2.tif'

# 1. Cargar las imágenes
img_patron = cv2.imread(img1, cv2.IMREAD_GRAYSCALE)
img_patron2 = cv2.imread(img2) # Corregido: antes tenías 'imp_patron2'

def analizar_imagen(img, titulo, es_color=False):
    # Verificación de seguridad para que no explote si la ruta falla
    if img is None:
        print(f"Error: No se pudo leer {titulo}. Verifica que la terminal esté en la carpeta 'Practica'.")
        return

    plt.figure(figsize=(12, 5))

    # Visualización
    plt.subplot(1, 2, 1)
    if es_color:
        # Convertir BGR (OpenCV) a RGB (Matplotlib)
        plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    else:
        plt.imshow(img, cmap='gray')
    plt.title(f'Imagen: {titulo}')
    plt.axis('off')

    # Histograma
    plt.subplot(1, 2, 2)
    if es_color:
        colores = ('b', 'g', 'r')
        for i, col in enumerate(colores):
            hist = cv2.calcHist([img], [i], None, [256], [0, 256])
            plt.plot(hist, color=col, label=f'Canal {col.upper()}')
    else:
        hist = cv2.calcHist([img], [0], None, [256], [0, 256])
        plt.plot(hist, color='black')
    
    plt.title(f'Histograma: {titulo}')
    plt.xlabel('Intensidad de pixel')
    plt.ylabel('Cantidad de pixeles')
    plt.legend() if es_color else None
    plt.grid(True)
    plt.show()

# 2. Llamar a la función
analizar_imagen(img_patron, "patron.tif (Gris)")
analizar_imagen(img_patron2, "patron2.tif (Color)", es_color=True)