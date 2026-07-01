import cv2
import numpy as np
import matplotlib.pyplot as plt

# 1. Carga de diferentes imágenes (Manual)
img1 = cv2.imread('imagen1.jpg') 
img2 = cv2.imread('imagen2.jpg')
img3 = cv2.imread('imagen3.jpg') 

# Verificamos que se cargaron bien
imagenes = [img1, img2, img3]
nombres = ['Logo 1', 'Logo 2', 'Logo 3']

for i, img in enumerate(imagenes):
    if img is None:
        print(f"Error: No se pudo cargar la {nombres[i]}")
        continue

    # 2. Mostrar en pantalla información sobre las imágenes
    print(f"--- {nombres[i]} ---")
    print("- Dimensiones:", img.shape) 
    print("- Tipo de dato:", img.dtype)

    # 3. Leer y escribir un valor puntual 
    # OpenCV usa BGR 
    valor_px = img[20, 20].copy() 
    print(f"- Valor original en (20,20): {valor_px}") 
    img[20, 20] = [255, 255, 255] 

    # 5. (ROI)
    # Formato: imagen[y0:y1, x0:x1]
    roi = img[100:400, 100:400].copy() #

    cv2.line(img, (0, 0), (img.shape[1], img.shape[0]), (255, 0, 0), 3)
    cv2.circle(img, (200, 200), 50, (0, 0, 255), 3)
    cv2.rectangle(img, (100, 100), (400, 400), (0, 255, 0), 3)

    # 6. Función para mostrar varias imágenes en una sola ventana
    # Usamos matplotlib para mostrar la original y su ROI juntas
    plt.figure(figsize=(10, 4))
    
    plt.subplot(1, 2, 1) 
    plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB)) 
    plt.title(f"{nombres[i]} con dibujos")

    plt.subplot(1, 2, 2) 
    plt.imshow(cv2.cvtColor(roi, cv2.COLOR_BGR2RGB))
    plt.title(f"ROI de {nombres[i]}")
    
    plt.show() 

    # 1. Escritura de la imagen (Guardado)
    cv2.imwrite(f'resultado_{i}.png', img)

cv2.destroyAllWindows() 