import cv2
import numpy as np
import matplotlib.pyplot as plt

# ==========================================
# 1. Operaciones Básicas
# ==========================================
def operaciones_aritmeticas(img1, img2, mascara):
    # Convertimos a float32 para evitar desbordes durante los cálculos
    img1_f = img1.astype(np.float32)
    img2_f = img2.astype(np.float32)

    # a) Suma: Normalizar por el número de imágenes
    suma = ((img1_f + img2_f) / 2.0).astype(np.uint8)

    # b) Diferencia: Aplicar reescalado
    diff = img1_f - img2_f
    
    # Método 1: sumar 255 y dividir por 2
    diff_m1 = ((diff + 255) / 2.0).astype(np.uint8)
    
    # Método 2: restar el mínimo y escalar a 255
    diff_min = np.min(diff)
    diff_m2 = diff - diff_min
    diff_max = np.max(diff_m2)
    if diff_max != 0: 
        diff_m2 = (diff_m2 * (255.0 / diff_max)).astype(np.uint8)
    else:
        diff_m2 = diff_m2.astype(np.uint8)

    # c) Multiplicación: Multiplicar imagen por máscara binaria
    mascara_norm = (mascara / 255.0).astype(np.float32)
    multiplicacion = (img1_f * mascara_norm).astype(np.uint8)

    # Mostrar resultados (¡AHORA CON vmin Y vmax!)
    fig, axs = plt.subplots(2, 3, figsize=(12, 8))
    fig.suptitle("Operaciones Aritméticas", fontsize=16)
    
    axs[0,0].imshow(img1, cmap='gray', vmin=0, vmax=255); axs[0,0].set_title("Imagen 1")
    axs[0,1].imshow(img2, cmap='gray', vmin=0, vmax=255); axs[0,1].set_title("Imagen 2")
    axs[0,2].imshow(suma, cmap='gray', vmin=0, vmax=255); axs[0,2].set_title("a) Suma")
    axs[1,0].imshow(diff_m1, cmap='gray', vmin=0, vmax=255); axs[1,0].set_title("b) Resta (Método 1)")
    axs[1,1].imshow(diff_m2, cmap='gray', vmin=0, vmax=255); axs[1,1].set_title("b) Resta (Método 2)")
    axs[1,2].imshow(multiplicacion, cmap='gray', vmin=0, vmax=255); axs[1,2].set_title("c) Multiplicación (ROI)")
    
    for ax in axs.flat: ax.axis('off')
    plt.tight_layout()
    plt.show()

# ==========================================
# 2. Extracción de fondo en video
# ==========================================
def extraer_fondo_video(video_path):
    print("Cargando video en memoria, por favor espera...")
    cap = cv2.VideoCapture(video_path)
    
    if not cap.isOpened():
        print(f"Error: No se encontró el video '{video_path}'.")
        return

    frames = []
    # Leemos hasta 100 frames para no colapsar la RAM y que sea fluido
    while cap.isOpened() and len(frames) < 100:
        ret, frame = cap.read() # Lee un frame y deja el puntero en el próximo
        if not ret:
            break
        frame_gris = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        frames.append(frame_gris.astype(np.float32))
        
    cap.release()
    print(f"Se cargaron {len(frames)} frames. Abriendo ventana...")

    if len(frames) == 0:
        return

    # Función que se ejecuta cada vez que movemos el Trackbar
    def actualizar_trackbar(val):
        num_frames_a_promediar = max(1, val) # Evitamos promediar 0 frames
        
        # Tomamos el subconjunto de frames y los sumamos (Acumulador)
        frames_seleccionados = frames[:num_frames_a_promediar]
        acumulador = np.sum(frames_seleccionados, axis=0)
        
        # Calcular el promedio dividiendo el acumulador por frames_leidos. Convertir a uint8.
        fondo = (acumulador / num_frames_a_promediar).astype(np.uint8)
        
        # Mostramos el resultado
        cv2.imshow('Extraccion de Fondo', fondo)

    # Creamos la ventana y el Trackbar nativo de OpenCV 
    cv2.namedWindow('Extraccion de Fondo')
    cv2.createTrackbar('Frames a promediar', 'Extraccion de Fondo', 1, len(frames), actualizar_trackbar)
    
    # Forzamos la primera actualización
    actualizar_trackbar(1)
    
    print("Mueve el deslizador en la ventana emergente. Presiona 'ESC' en esa ventana para salir.")
    # Bucle de espera hasta apretar ESC
    while True:
        if cv2.waitKey(1) & 0xFF == 27: 
            break
            
    cv2.destroyAllWindows()


# ==========================================
# BLOQUE PRINCIPAL
# ==========================================
if __name__ == "__main__":
    
    # --- PRUEBA 1: Operaciones Aritméticas ---
    # Creamos un par de imágenes falsas simples para probar (puedes cambiarlas por imgs reales)
    img_a = np.ones((200, 200), dtype=np.uint8) * 150  # Gris claro
    img_b = np.ones((200, 200), dtype=np.uint8) * 50   # Gris oscuro
    
    # Creamos una máscara (Círculo blanco en fondo negro)
    mascara_test = np.zeros((200, 200), dtype=np.uint8)
    cv2.circle(mascara_test, (100, 100), 50, 255, -1)
    
    print("Mostrando Operaciones Aritméticas...")
    operaciones_aritmeticas(img_a, img_b, mascara_test)
    
    # --- PRUEBA 2: Video ---
    # Ajusta esta ruta según donde tengas descargado el video
    ruta_video = '../../imagenes/pedestrians.mp4'
    extraer_fondo_video(ruta_video)