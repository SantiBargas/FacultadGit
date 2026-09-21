import pandas as pd
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt
from sklearn.metrics import davies_bouldin_score
from sklearn.metrics import DistanceMetric

# Cargar el dataset Iris
df = pd.read_csv('irisbin_trn.csv')
arreglo = df.to_numpy()
x = arreglo[: , :-3] 

k_values = list(range(2, 11)) #Probamos k con valores de 2 a 10
print(k_values)
inertia_values = [] #inertia_values es donde almacenaremos los valores de inercia (una medida de qué tan compactos son los clusters).
silhouette_scores = [] #silhouette_scores almacenará los puntajes de la silueta, que mide la separación de los clusters.

#La inercia mide la suma de las distancias cuadradas de los puntos a su centroide más cercano. 
# Cuanto más baja la inercia, mejor están ajustados los puntos dentro de sus clusters.

#El puntaje de siulueta Es una métrica que evalúa cuán bien están separados los clusters.
#Va de -1 a 1, donde 1 significa que los clusters están muy bien separados y -1 que los puntos están mal agrupados.

#Un cluster es un grupo de datos o puntos en un conjunto de datos que tienen características similares entre sí

# Probar diferentes valores de k
for k in k_values:
    kmeans = KMeans(n_clusters=k, random_state=42) #random_state para dejar los mismos datos
    kmeans.fit(x) #se entrenan los clusters.
    inertia_values.append(kmeans.inertia_)
    
    # Calcular el puntaje de la métrica de silueta
    silhouette_avg = silhouette_score(x, kmeans.labels_)
    silhouette_scores.append(silhouette_avg)
    DVB=davies_bouldin_score(x, kmeans.labels_)
    print(DVB)


# Graficar los resultados
plt.figure(figsize=(10, 5))

# Gráfico de inercia
plt.subplot(1, 2, 1)
plt.plot(k_values, inertia_values, marker='o')
plt.title('Inercia vs número de clusters')
plt.xlabel('Número de clusters (k)')
plt.ylabel('Inercia')

# Gráfico de puntaje de silueta
plt.subplot(1, 2, 2)
plt.plot(k_values, silhouette_scores, marker='o', color='red')
plt.title('')
plt.xlabel('Número de clusters (k)')
plt.ylabel('Puntaje de silueta')

plt.tight_layout()
plt.show()
# Imprimir el mejor valor de k según el puntaje de silueta
best_k = k_values[silhouette_scores.index(max(silhouette_scores))]
print(f"El valor óptimo de k es: {best_k}")

#Inercia mide qué tan compactos son los clusters. 
#es la suma de las distancias cuadradas entre cada punto de datos y su centroide (el centro del cluster más cercano).
#El "punto de codo" suele usarse para elegir el número óptimo de clusters, donde la disminución de la inercia se vuelve más lenta. 
#En este caso, parece estar entre k=3 y k=4, ya que después de esos valores, el descenso es menos pronunciado.

#Puntaje de silueta es una métrica que mide qué tan bien separado está cada cluster de los demás. Un valor de 1 indica que los clusters están bien separados,
#mientras que un valor cercano a -1 indica que los puntos están asignados incorrectamente a un cluster
#Conclusión: El valor de k con el puntaje de silueta más alto es 2, lo que sugiere que dos clusters dan la mejor separación de los datos.
