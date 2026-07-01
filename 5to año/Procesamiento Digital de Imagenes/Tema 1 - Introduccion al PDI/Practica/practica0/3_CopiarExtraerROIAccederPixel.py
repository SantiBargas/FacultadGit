#incluir la biblioteca
import cv2
#leer la imagen, mostrar sus dimensiones y tipo de dato
imagen = cv2.imread('OpenCV-Logo.png')
print("Dimensiones de la imagen: ", imagen.shape)
print("Tipo de dato de la imagen", imagen.dtype)

imagen2 = imagen.copy()
print("Dimensiones de la imagen2: ", imagen2.shape)

x0, y0 = 100, 100
x1, y1 = 300, 300
imagenRoi = imagen[x0:x1, y0:y1].copy()
print("Dimensiones de la imagenRoi: ", imagenRoi.shape)

y=150
x=150
valor_px = imagen[y,x]
print("Valor del pixel en (", x, ",", y, "): ", valor_px)


cv2.imshow("Hello World", imagen)
cv2.waitKey(0)
cv2.destroyAllWindows()