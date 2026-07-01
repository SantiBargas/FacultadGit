#incluir la biblioteca
import cv2
import numpy as np
#leer la imagen, mostrar sus dimensiones y tipo de dato
imagen = cv2.imread('OpenCV-Logo.png')
imagen_nueva = np.zeros(imagen.shape, dtype = imagen.dtype)
imagen_gray = cv2.imread('OpenCV-Logo.png', cv2.IMREAD_GRAYSCALE)
imagen_gray2 = cv2.imread('OpenCV-Logo.png', cv2.IMREAD_COLOR)
imagen_gray3 = cv2.cvtColor(imagen_gray2, cv2.COLOR_BGR2GRAY)
cv2.imshow("Hello World", imagen)
cv2.imshow("Hello World1", imagen_nueva)
cv2.imshow("Hello World2", imagen_gray)
cv2.imshow("Hello World3", imagen_gray2)
cv2.imshow("Hello World4", imagen_gray3)
cv2.waitKey(0)

cv2.imwrite('nueva_imagen.jpg', imagen)
cv2.imwrite('nueva_imagen_nueva.jpg', imagen_nueva)
cv2.imwrite('nueva_imagen_gris.jpg', imagen_gray)
cv2.imwrite('nueva_imagen_gris2.jpg', imagen_gray2)
cv2.imwrite('nueva_imagen_gris3.jpg', imagen_gray3)