import cv2
import numpy as np

def nada(x):
    pass

# Inicializar la webcam
cap = cv2.VideoCapture(0)

# Crear una ventana para los controles
cv2.namedWindow('Controles HSV')
cv2.createTrackbar('H Min', 'Controles HSV', 0, 179, nada)
cv2.createTrackbar('S Min', 'Controles HSV', 0, 255, nada)
cv2.createTrackbar('V Min', 'Controles HSV', 0, 255, nada)
cv2.createTrackbar('H Max', 'Controles HSV', 179, 179, nada)
cv2.createTrackbar('S Max', 'Controles HSV', 255, 255, nada)
cv2.createTrackbar('V Max', 'Controles HSV', 255, 255, nada)

while True:
    ret, frame = cap.read()
    if not ret: break

    # Convertir el frame de BGR a HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Leer las posiciones actuales de las trackbars
    h_min = cv2.getTrackbarPos('H Min', 'Controles HSV')
    s_min = cv2.getTrackbarPos('S Min', 'Controles HSV')
    v_min = cv2.getTrackbarPos('V Min', 'Controles HSV')
    h_max = cv2.getTrackbarPos('H Max', 'Controles HSV')
    s_max = cv2.getTrackbarPos('S Max', 'Controles HSV')
    v_max = cv2.getTrackbarPos('V Max', 'Controles HSV')

    # Crear los arrays de límites
    lower = np.array([h_min, s_min, v_min])
    upper = np.array([h_max, s_max, v_max])

    # Generar máscara y aplicar bitwise
    mascara = cv2.inRange(hsv, lower, upper)
    resultado = cv2.bitwise_and(frame, frame, mask=mascara)

    # Mostrar las ventanas
    cv2.imshow('Original', frame)
    cv2.imshow('Mascara', mascara)
    cv2.imshow('Segmentacion', resultado)

    # Presionar 'q' para salir
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()