import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt

# Dama: 9 puntos;
# Torre: 5 puntos;
# Alfil: 3 puntos;
# Caballo: 3 puntos;
# Peón: 1 punto


# Cargamos la imagen
img = cv.imread('B00.png', cv.IMREAD_GRAYSCALE)
img_binaria = cv.threshold(img,70, 255, cv.THRESH_BINARY_INV)[1]

plt.imshow(img_binaria, cmap='gray')
plt.axis('off')
plt.show()


# Modelamos el tablero
tamano_celda = 90 # 720 / 8 (Tamaño de cada celda)
tablero = np.empty((8, 8), dtype=object)

# Coords. de cada celda
for fila in range(8):
  for col in range(8):
    x1 = col * tamano_celda
    y1 = fila * tamano_celda
    x2 = x1 + tamano_celda
    y2 = y1 + tamano_celda
    tablero[fila, col] = (x1, y1, x2, y2)

# Kernel para aplicar dilatacion
kernel = np.array((3, 3), dtype=np.uint8)

# Contadores de puntaje
contador_negras = 0
contador_blancas = 0

for i in range(tablero.shape[0]):       # fila
    for j in range(tablero.shape[1]):   # columna
        celda = tablero[i, j]
        ficha = img_binaria[celda[1]:celda[3], celda[0]:celda[2]] # Extraemos la ficha de esa celda

        img_dilate = cv.dilate(ficha, kernel)
        
        # Contamos la cant de px blancos 
        ficha_contador = cv.countNonZero(img_dilate)
        
        if ficha_contador >= 1400: # La ficha es negra 
            if ficha_contador < 1600: 
                print(f"FICHA: {i+1}, {j+1} - Peón Negro")
                contador_negras += 1
            elif ficha_contador > 2050 and ficha_contador < 2150:
                print(f"FICHA: {i+1}, {j+1} - Alfil Negro")
                contador_negras += 3
            elif ficha_contador >= 2150 and ficha_contador <= 2200: 
                print(f"FICHA: {i+1}, {j+1} - Torre Negra")
                contador_negras += 5
            elif ficha_contador >= 2400 and ficha_contador <= 2550:
                print(f"FICHA: {i+1}, {j+1} - Caballo Negro")
                contador_negras += 3
            elif ficha_contador >= 2700 and ficha_contador < 2760:
                print(f"FICHA: {i+1}, {j+1} - Reina Negra")
                contador_negras += 9
        elif ficha_contador > 500 and ficha_contador < 1400: # La ficha es blanca
            bordes = cv.Canny(ficha, 100, 110)
            contador_borde = cv.countNonZero(bordes)
            if contador_borde < 500: 
                print(f"FICHA: {i+1}, {j+1} - Peón Blanco")
                contador_blancas += 1
            elif contador_borde >=500 and contador_borde < 550:
                print(f"FICHA: {i+1}, {j+1} - Alfil Blanco")
                contador_blancas += 3
            elif contador_borde >= 550 and contador_borde <= 582:
                print(f"FICHA: {i+1}, {j+1} - Torre Blanca")
                contador_blancas += 5
            elif contador_borde > 582 and contador_borde <= 650:
                print(f"FICHA: {i+1}, {j+1} - Caballo Blanco")
                contador_blancas += 3
            elif contador_borde >= 720 and contador_borde <= 780:
                print(f"FICHA: {i+1}, {j+1} - Reina Blanca")
                contador_blancas += 9
            
print(f"Total Puntos Negras: {contador_negras}")
print(f"Total Puntos Blancas: {contador_blancas}")
