#incluir la biblioteca
import cv2
#leer la imagen, mostrar sus dimensiones y tipo de dato
imagen = cv2.imread('OpenCV-Logo.png')
print("Dimensiones de la imagen: ", imagen.shape)
print("Tipo de dato de la imagen", imagen.dtype)
#mostrar la imagen en una ventana hasta que se presione una tecla y destruir ventana
cv2.imshow("Hello World", imagen)
cv2.waitKey(0)
cv2.destroyAllWindows()