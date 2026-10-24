import numpy as np
from sklearn.datasets import load_digits
from sklearn.model_selection import KFold
from sklearn.neural_network import MLPClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC

RANDOM_STATE = 0

# Cargar datos (mismo dataset que Ejercicio 1)
digits = load_digits()
X, y = digits.data, digits.target

print(X.shape[0], "patrones,", X.shape[1], "atributos,", len(np.unique(y)), "clases")

# Mismos 5 pliegues para TODOS los clasificadores
kf = KFold(n_splits=5, shuffle=True, random_state=RANDOM_STATE)
folds = list(kf.split(X))
# kf.split(X) es un generador que se agota al recorrerlo una vez.
# Lo guardamos en una lista para poder reutilizar los MISMOS 5 pliegues
# en los 6 clasificadores, y que la comparacion sea justa.


# Definimos los clasificadores a comparar, con sus parametros
def crear_mlp():
    return MLPClassifier(hidden_layer_sizes=(32,), activation='relu', solver='lbfgs', max_iter=1000, random_state=RANDOM_STATE)

def crear_nb(): #Naive Bayes
    return GaussianNB()

def crear_lda(): #Analisis Discriminante Lineal
    return LinearDiscriminantAnalysis()

def crear_knn(): #K vecinos mas cercanos
    return KNeighborsClassifier(n_neighbors=5)

def crear_arbol(): #Arbol de decision
    return DecisionTreeClassifier(max_depth=10, random_state=RANDOM_STATE)

def crear_svm(): #Maquina de vectores de soporte
    return SVC(kernel='rbf', random_state=RANDOM_STATE)

def evaluar_clasificador(crear_clf,nombre):
    aciertos =[]
    for idx_train, idx_test in folds:
        clf = crear_clf()
        clf.fit(X[idx_train], y[idx_train])
        aciertos.append(clf.score(X[idx_test], y[idx_test]))
    print(f"=== {nombre} ===")
    print(f"Aciertos por particion: {aciertos}")
    print(f"Media: {np.array(aciertos).mean():.4f}")
    print(f"Varianza: {np.array(aciertos).var():.4f}")
    print()

# Corremos la evaluacion para cada clasificador, uno por uno
evaluar_clasificador(crear_mlp, "MLP")
evaluar_clasificador(crear_nb, "Naive Bayes")
evaluar_clasificador(crear_lda, "LDA")
evaluar_clasificador(crear_knn, "KNN")
evaluar_clasificador(crear_arbol, "Arbol de decision")
evaluar_clasificador(crear_svm, "SVM")