import numpy as np
from sklearn.datasets import load_wine
from sklearn.model_selection import KFold
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import BaggingClassifier, AdaBoostClassifier

RANDOM_STATE = 0

# Cargar datos
wine = load_wine()
X, y = wine.data, wine.target
print(f"Dataset Wine: {X.shape[0]} patrones, {X.shape[1]} atributos, {len(np.unique(y))} clases")
print(X)

# Mismos 5 pliegues para ambos metodos, para que la comparacion sea justa
kf = KFold(n_splits=5, shuffle=True, random_state=RANDOM_STATE)
folds = list(kf.split(X))

# Definimos los ensambles a comparar, con sus parametros
def crear_bagging():
    # Bagging: entrena N arboles independientes
    # Cada uno con una muestra bootstrap distinta
    # Una muestra bootstrap es una muestra aleatoria con reemplazo del dataset original, de igual tamaño que el dataset original.     
    # promedia (vota) sus predicciones. 
    # Busca reducir la VARIANZA de un modelo base que individualmente es inestable/sobreajusta.
    return BaggingClassifier(
        estimator=DecisionTreeClassifier(random_state=RANDOM_STATE), #definimos arbol de decision como modelo base
        n_estimators=50, #50 arboles, cada uno con una muestra bootstrap distinta
        random_state=RANDOM_STATE
    )
BaggingClassifier()

def crear_adaboost():
    # AdaBoost: entrena N arboles SECUENCIALMENTE, dandole mas peso en cada
    # ronda a los patrones que el arbol anterior clasifico mal. Busca reducir
    # el SESGO combinando muchos modelos simples, no promediar modelos fuertes.
    return AdaBoostClassifier(
        estimator=DecisionTreeClassifier(max_depth=2, random_state=RANDOM_STATE),
        n_estimators=50,
        random_state=RANDOM_STATE
    )

# Evalua un ensamble (recibe la funcion que lo crea) en los 5 pliegues
def evaluar(crear_clf, nombre):
    aciertos = []
    for idx_train, idx_test in folds:
        clf = crear_clf()
        clf.fit(X[idx_train], y[idx_train])
        aciertos.append(clf.score(X[idx_test], y[idx_test]))
    aciertos = np.array(aciertos)

    print(f"=== {nombre} ===")
    print(f"Aciertos por particion: {aciertos}")
    print(f"Media: {aciertos.mean():.4f}")
    print(f"Varianza: {aciertos.var():.4f}")
    print()


evaluar(crear_bagging, "Bagging")
evaluar(crear_adaboost, "AdaBoost")
