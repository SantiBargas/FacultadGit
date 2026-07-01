import cv2
import numpy as np
import matplotlib.pyplot as plt

def transformaciones_no_lineales(img_path, gamma_val=0.5):
    # Cargamos la imagen en escala de grises
    img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
    if img is None:
        print(f"Error: No se pudo cargar la imagen '{img_path}'. Revisa la ruta.")
        return

    # IMPORTANTE: Para operaciones matemáticas, convertir a float
    img_float = img.astype(np.float32)

    # ==========================================
    # 1. Transformación Logarítmica: s = log(1 + r)
    # ==========================================
    # Para normalizar, multiplicamos por una constante 'c' de modo que 
    # el píxel más brillante quede escalado a 255.
    c_log = 255.0 / np.log(1 + np.max(img_float))
    img_log_calc = c_log * np.log(1 + img_float)
    img_log = np.clip(img_log_calc, 0, 255).astype(np.uint8)

    # ==========================================
    # 2. Transformación de Potencia (Gamma): s = r^gamma (c=1)
    # ==========================================
    gamma = gamma_val 
    # Normalizamos primero la imagen al rango [0, 1] para aplicar la potencia
    img_norm = img_float / 255.0
    img_gamma_calc = (img_norm ** gamma) * 255.0
    img_gamma = np.clip(img_gamma_calc, 0, 255).astype(np.uint8)

    # Mostrar resultados
    fig, axs = plt.subplots(1, 3, figsize=(15, 5))
    
    # Extraemos solo el nombre del archivo para el título
    nombre_archivo = img_path.split('/')[-1]
    
    axs[0].imshow(img, cmap='gray')
    axs[0].set_title(f"Original ({nombre_archivo})")
    
    axs[1].imshow(img_log, cmap='gray')
    axs[1].set_title("Logarítmica")
    
    axs[2].imshow(img_gamma, cmap='gray')
    axs[2].set_title(f"Potencia (Gamma={gamma})")
    
    for ax in axs: 
        ax.axis('off')
        
    plt.tight_layout()
    plt.show()

# ==========================================
# BLOQUE PRINCIPAL
# ==========================================
if __name__ == "__main__":
    # Rutas locales basadas en tu estructura de carpetas
    ruta_rmn = '../../imagenes/rmn.jpg'
    ruta_earth = '../../imagenes/earth.bmp'
    
    print("Procesando rmn.jpg...")
    # 1. Realice el procesado sobre la imagen 'rmn.jpg'
    transformaciones_no_lineales(ruta_rmn, gamma_val=0.5)
    
    print("Procesando earth.bmp...")
    # 2. Evalúe sobre alguna otra (earth.bmp suele ser oscura, ideal para esto)
    transformaciones_no_lineales(ruta_earth, gamma_val=0.4)