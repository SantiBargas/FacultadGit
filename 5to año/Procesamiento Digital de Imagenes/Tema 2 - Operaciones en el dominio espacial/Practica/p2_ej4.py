import cv2
import numpy as np
import matplotlib.pyplot as plt

# ==========================================
# Caso 1: Astronomía (earth.bmp)
# ==========================================
def realzar_objetos_ocultos(img_path='../../imagenes/earth.bmp'):
    """
    Objetivo: Hacer visibles objetos ocultos en la imagen con buen contraste[cite: 42].
    """
    img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        print(f"Error: No se encontró {img_path}")
        return

    # PASO 1 y 2: Transformación no lineal (Potencia / Gamma)
    # Una corrección gamma con un valor menor a 1 (ej. 0.2) es ideal para 
    # estirar agresivamente los grises muy oscuros sin quemar los blancos.
    img_float = img.astype(np.float32) / 255.0
    gamma = 0.2 
    img_realzada_calc = (img_float ** gamma) * 255.0

    # PASO 3: Normalizar
    img_realzada = np.clip(img_realzada_calc, 0, 255).astype(np.uint8)

    # Visualización
    fig, axs = plt.subplots(1, 2, figsize=(10, 5))
    axs[0].imshow(img, cmap='gray', vmin=0, vmax=255)
    axs[0].set_title("Imagen Original")
    axs[1].imshow(img_realzada, cmap='gray', vmin=0, vmax=255)
    axs[1].set_title(f"Imagen Realzada (Gamma = {gamma})")
    for ax in axs: ax.axis('off')
    plt.show()

# ==========================================
# Caso 2: Placas ASUS
# ==========================================
def clasificar_placa_madre(img_path):
    """
    Objetivo: Determinar si la placa es A7V600-x o A7V600-SE, tolerando ruido[cite: 43, 44, 46].
    """
    img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        print(f"Error al cargar {img_path}")
        return

    # PASO 1: Preprocesamiento (Manejo de ruido impulsivo)
    # El filtro de mediana es el mejor para eliminar ruido "sal y pimienta" 
    # sin difuminar los bordes de los componentes.
    img_procesada = cv2.medianBlur(img, 5)

    # PASO 2: Extracción de características
    # Generalmente estas placas difieren en la presencia de un chip específico en una zona.
    # Como la cámara es fija, podemos recortar una Región de Interés (ROI) donde sabemos
    # que está el cambio y medir su intensidad promedio.
    # (Nota: Ajusta estas coordenadas Y, X según dónde difieran realmente tus imágenes)
    roi = img_procesada[100:200, 300:400] 
    
    # Si el promedio de intensidad en esa zona es alto, hay un chip/conector brillante.
    intensidad_media = np.mean(roi) if roi.size > 0 else 0
    umbral = 100 

    es_modelo_SE = intensidad_media > umbral

    # PASO 3: Retornar resultado
    modelo = "A7V600-SE" if es_modelo_SE else "A7V600-x"

    plt.figure(figsize=(6,6))
    plt.imshow(img_procesada, cmap='gray')
    plt.title(f"Clasificación: {modelo} (Intensidad ROI: {intensidad_media:.1f})")
    plt.axis('off')
    plt.show()

    return modelo

# ==========================================
# Caso 3: Inspección de Blisters
# ==========================================
def inspeccionar_blister(img_path):
    img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        return

    # 1. Umbralización para dejar las pastillas en blanco
    _, mascara_pildoras = cv2.threshold(img, 150, 255, cv2.THRESH_BINARY)

    alto, ancho = mascara_pildoras.shape
    filas, columnas = 2, 5
    
    # SOLUCIÓN: Agregamos márgenes para ignorar el plástico negro de los bordes.
    # Estos porcentajes (12% ancho, 18% alto) ajustan la cuadrícula al centro.
    margen_x = int(ancho * 0.12)
    margen_y = int(alto * 0.18)

    ancho_efectivo = ancho - 2 * margen_x
    alto_efectivo = alto - 2 * margen_y

    alto_celda = alto_efectivo // filas
    ancho_celda = ancho_efectivo // columnas

    blister_completo = True
    img_resultado = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)

    # Recorremos la cuadrícula
    for i in range(filas):
        for j in range(columnas):
            # Calculamos las coordenadas sumando el margen inicial
            y_inicio = margen_y + i * alto_celda
            y_fin = margen_y + (i + 1) * alto_celda
            x_inicio = margen_x + j * ancho_celda
            x_fin = margen_x + (j + 1) * ancho_celda
            
            # Dibujamos la cuadrícula en verde para VISUALIZAR dónde estamos buscando
            cv2.rectangle(img_resultado, (x_inicio, y_inicio), (x_fin, y_fin), (0, 255, 0), 1)
            
            celda = mascara_pildoras[y_inicio:y_fin, x_inicio:x_fin]
            cantidad_blancos = cv2.countNonZero(celda)
            
            # Si hay menos del 15% de blanco en ese cuadradito, falta la pastilla
            umbral_area = (alto_celda * ancho_celda) * 0.15 
            
            if cantidad_blancos < umbral_area:
                blister_completo = False
                centro_x = x_inicio + ancho_celda // 2
                centro_y = y_inicio + alto_celda // 2
                # Círculo rojo indicando la falla
                cv2.circle(img_resultado, (centro_x, centro_y), 20, (0, 0, 255), 3)

    plt.figure(figsize=(8,4))
    plt.imshow(cv2.cvtColor(img_resultado, cv2.COLOR_BGR2RGB))
    titulo = "OK: Blister Completo" if blister_completo else "ALERTA: Blister Incompleto"
    plt.title(titulo)
    plt.axis('off')
    plt.show()

# ==========================================
# Caso 4 (Opcional): Esteganografía
# ==========================================
def ocultar_imagen_esteganografia(img_portadora_path, img_secreta_path):
    """
    Objetivo: Esconder una imagen binaria en una de grises usando LSB[cite: 53, 54].
    """
    portadora = cv2.imread(img_portadora_path, cv2.IMREAD_GRAYSCALE)
    secreta = cv2.imread(img_secreta_path, cv2.IMREAD_GRAYSCALE)

    if portadora is None or secreta is None:
        print("Error al cargar imágenes para esteganografía.")
        return None

    # Corregido: El shape devuelve (alto, ancho). Resize requiere (ancho, alto).
    secreta = cv2.resize(secreta, (portadora.shape[1], portadora.shape[0]))

    # Binarizar la secreta para que tenga valores de 0 o 1
    _, secreta_bin = cv2.threshold(secreta, 127, 1, cv2.THRESH_BINARY)

    # 1. Apagar el bit menos significativo (LSB) de la portadora usando AND con 254 (11111110)
    portadora_sin_lsb = cv2.bitwise_and(portadora, 254)
    
    # 2. Sumar la imagen secreta (que vale 0 o 1) al LSB
    img_esteganografica = cv2.bitwise_or(portadora_sin_lsb, secreta_bin)

    return img_esteganografica

def extraer_imagen_esteganografia(img_esteganografica):
    """
    Objetivo: Extraer la imagen binaria oculta aislando el LSB[cite: 54].
    """
    # Aislar el bit menos significativo usando AND con 1 (00000001)
    bits_extraidos = cv2.bitwise_and(img_esteganografica, 1)
    
    # Multiplicar por 255 para que los 1s se vuelvan blancos visibles
    img_extraida = bits_extraidos * 255
    
    return img_extraida


# ==========================================
# BLOQUE PRINCIPAL (Pruebas)
# ==========================================
if __name__ == "__main__":
    print("--- 1. Caso Astronomía ---")
    realzar_objetos_ocultos('../../imagenes/earth.bmp')

    print("\n--- 2. Caso Placas ASUS ---")
    clasificar_placa_madre('../../imagenes/a7v600-x.gif')
    clasificar_placa_madre('../../imagenes/a7v600-SE(RImpulsivo).gif')

    print("\n--- 3. Caso Blisters ---")
    inspeccionar_blister('../../imagenes/blister_completo.jpg')
    inspeccionar_blister('../../imagenes/blister_incompleto.jpg')

    print("\n--- 4. Caso Esteganografía ---")
    # Para probar esto, puedes usar cualquier par de imágenes que tengas a mano
    oculta = ocultar_imagen_esteganografia('../../imagenes/earth.bmp', '../../imagenes/building.jpg')
    if oculta is not None:
        extraida = extraer_imagen_esteganografia(oculta)
        
        fig, axs = plt.subplots(1, 2, figsize=(10, 5))
        axs[0].imshow(oculta, cmap='gray'); axs[0].set_title("Imagen Portadora (Se ve normal)")
        axs[1].imshow(extraida, cmap='gray'); axs[1].set_title("Imagen Secreta Extraída")
        for ax in axs: ax.axis('off')
        plt.show()