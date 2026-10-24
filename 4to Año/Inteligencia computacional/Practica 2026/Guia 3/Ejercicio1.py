"""
Ejercicio 1 - Guia 3
Perceptron multicapa (MLP) sobre el dataset Digits: comparacion de
train_test_split (1 particion) vs KFold (5 y 10 particiones).
"""

import numpy as np
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split, KFold
from sklearn.neural_network import MLPClassifier

RANDOM_STATE = 0 #fijamos la semilla para que los resultados sean comparables, es decir siempre que se ejecute el codigo se obtengan los mismos resultados con los mismos numeros aleatorios

# Cargar datos
digits = load_digits()
X, y = digits.data, digits.target


def crear_mlp():
    """Crea una instancia nueva del MLP con la misma arquitectura, para
    que la comparacion entre esquemas de particion sea justa."""
    return MLPClassifier(
        hidden_layer_sizes=(32,), #capas ocultas
        activation='relu', #funcion de activacion
        solver='lbfgs',
        max_iter=1000, #maximo de iteraciones
        random_state=RANDOM_STATE #semilla random
    )
#usamos 'relu' porque no achica tanto el error al propagarlo hacia atras (evita que las primeras capas dejen de aprender) y es mas rapida de calcular
#solver='lbfgs', #algoritmo de optimizacion de pesos; mejor que el default 'adam' para datasets chicos como Digits
#backprop calcula "cuánto se equivocó cada peso"; el solver decide "cuánto y cómo corregirlo, vuelta tras vuelta", hasta que la red deja de mejorar.

#FORMULA DE ACTUALIZACION DE PESOS DE LBFGS:
#peso_nuevo = peso_viejo - alpha * H⁻¹ * gradiente
#alpha es la tasa de aprendizaje, H⁻¹ es la inversa de la matriz Hessiana (segunda derivada de la funcion de error)

# --- Esquema A: 1 particion con train_test_split ---
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=RANDOM_STATE
)
#test_size=0.3 significa que el 30% de los datos se usaran para test y el 70% para entrenamiento

clf = crear_mlp()
clf.fit(X_train, y_train) #entrenamos el modelo con los datos de entrenamiento
aciertos = clf.score(X_test, y_test) #calculamos el acierto en el conjunto de test

print("=== Esquema A: 1 particion (train_test_split) ===")
print(f"Acierto en test: {aciertos:.4f}")
print()


# --- Esquemas B y C: KFold con distinto numero de particiones ---
def evaluar_kfold(n_splits):
    kf = KFold(n_splits=n_splits, shuffle=True, random_state=RANDOM_STATE)
    #kf es un objeto que define COMO particionar los datos en n_splits, luego llamaos a kf.split(X) para obetener los indices de cada particion
    
    #shuffle=True significa que los datos se mezclan antes de dividirlos en particiones
    aciertos = []
    for idx_train, idx_test in kf.split(X):
        clf = crear_mlp() #creamos un nuevo clasificador para cada particion
        clf.fit(X[idx_train], y[idx_train]) #entrenamos
        aciertos.append(clf.score(X[idx_test], y[idx_test])) #vemos aciertos
    return np.array(aciertos) #concatenamos a un array de numpy para poder calcular la media y varianza facilmente


for k in (5, 10): #5 y 10 particiones
    aciertos = evaluar_kfold(k)
    print(f"=== Esquema: KFold con {k} particiones ===")
    print(f"Aciertos por particion: {aciertos}")
    print(f"Media: {aciertos.mean():.4f}")
    print(f"Varianza: {aciertos.var():.4f}")
    print()

#media mide la mejor estimacion promedio
#varianza mide la dispersion de los aciertos, es decir que tan lejos estan los aciertos de la media