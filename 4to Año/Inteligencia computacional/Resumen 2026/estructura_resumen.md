# Estructura propuesta para el resumen (Google Docs)

## Índice corto (Título = Unidad, Subtítulo = tema)

UNIDAD 1 — Introducción

UNIDAD 2 — Perceptrón Simple

UNIDAD 3
  Perceptrón Multicapa (MLP)
  Backpropagation
  Redes con Funciones de Base Radial (RBF-NN)
  Mapas Autoorganizativos (SOM)
  Redes Neuronales Dinámicas (Hopfield)

UNIDAD 4
  Capacidad de Generalización
  Aprendizaje No Neuronal (kNN, Árboles, Naive Bayes, SVM)
  Ensambles de Clasificadores (Bagging, Stacking, Boosting, AdaBoost, Gradient Boosting)
  Clustering

UNIDAD 5
  Autómatas Celulares y Agentes
  Computación Evolutiva: Algoritmos Genéticos
  Variantes de Computación Evolutiva (Estrategias de Evolución, Programación Genética)

UNIDAD 6
  Colonia de Hormigas (ACO)
  Enjambre de Partículas (PSO)

UNIDAD 7
  Teoría de Conjuntos Borrosos
  Memorias Asociativas Borrosas (FAM)

## Detalle (Título 1 = Unidad · Título 2 = bloque temático · Título 3 = subtema puntual)

Mismo contenido de arriba, abierto en subtemas puntuales por si querés bajar un nivel más
en el Doc. Basado en el temario oficial de la planificación 2026 y en el orden real de los
PDFs de la cátedra (mismo orden que `../Resumenes/preguntas_de_repaso.txt`).

## UNIDAD 1 — Introducción

- Breve reseña histórica de la inteligencia computacional
- Áreas del conocimiento involucradas y relación con la inteligencia artificial
- El cerebro humano y las limitaciones del cálculo computacional
- Impacto y aplicaciones de la inteligencia computacional
- Clasificación e introducción conceptual a las técnicas de IC

## UNIDAD 2 — Redes Neuronales 1 (Perceptrón Simple)

### Inspiración biológica
- Fisiología neuronal básica
- Redes de neuronas biológicas y escalas de organización estructural del cerebro

### Modelo de neurona
- La sinapsis
- Funciones de activación
- 6 características de las redes neuronales
- Simplificaciones del modelo de neurona

### Perceptrón simple
- De la neurona al modelo formal (los 3 pasos hasta x0 y w0)
- Ecuación formal
- Sesgo / bias: qué es y para qué sirve
- Hiperplanos para la separación de clases
- Tipos de entrenamiento y cómo funciona cada uno
- Limitaciones del perceptrón simple

### Generalidades
- Clasificación de arquitecturas neuronales
- Clasificación de los procesos de aprendizaje

## UNIDAD 3 — Redes Neuronales 2

### Perceptrón Multicapa (MLP)
- Por qué no alcanza el perceptrón simple
- Arquitectura: notación matricial, capas
- Función de activación (por qué ya no es la signo)
- Criterio de error

### Backpropagation
- Propagación hacia adelante
- Propagación hacia atrás
- Por qué se llama "retropropagación"
- Concepto de época
- Velocidad de aprendizaje y término de momento
- Inicialización y criterios de finalización
- Definición de topología y parámetros de entrenamiento

### Redes con Funciones de Base Radial (RBF-NN)
- Qué es una red de base radial, objetivo
- Arquitectura y fronteras de decisión
- Entrenamiento
- Modelo matemático: φj(x) y salida
- Cálculo de σ de cada neurona radial

### Mapas Autoorganizativos (SOM)
- Arquitectura
- Algoritmo de entrenamiento: neurona ganadora, inicialización, adaptación de pesos
- Alcance (Ag) y velocidad de aprendizaje (η): por qué variables y decrecientes, 3 etapas
- Formación de mapas topológicos: vecindad vs. sin vecindad
- LVQ: diferencias con SOM

### Redes Neuronales Dinámicas
- Por qué "dinámica"
- Las 3 aproximaciones (gráfico)
- TDNN vs. RNN
- Red de Hopfield: arquitectura, modelo matemático, entrenamiento y prueba (gráfico)
- Campos energéticos: valles espurios, por qué aparecen
- BPTT, Elman y Jordan

## UNIDAD 4 — Aprendizaje Automático

### Capacidad de generalización
- Superficies de error: mínimos locales y globales
- Sobre-entrenamiento: qué es, cómo se evita
- Validación cruzada: leave-k-out, leave-1-out, solapar particiones

### Aprendizaje automático no neuronal
- kNN: funcionamiento, ventajas y desventajas
- Árboles de decisión: impureza de Gini, entropía, ganancia de información; ventajas y
  desventajas
- Naive Bayes: por qué "ingenuo"; ventajas y desventajas
- SVM: margen, vectores de soporte, truco del kernel; ventajas y desventajas

### Ensambles de clasificadores
- Bagging: bootstrap, combinación del resultado
- Stacking: modelos simples + meta-modelo
- Boosting por muestreo (C1, C2, C3)
- AdaBoost: pesos de patrones, voto final
- Gradient Boosting: qué predice cada modelo nuevo (ejemplo precio de una casa)
- Ventajas y desventajas de los ensambles en general

### Clustering (aprendizaje no supervisado)
- Qué es, rol de la distancia
- Clustering jerárquico: aglomerativo vs. divisivo, dendrograma
- Métricas internas (cohesión, separación, Davies-Bouldin) y externas (Fowlkes-Mallows,
  Rand Index)
- Elección del número óptimo de clusters (k)

## UNIDAD 5 — Inteligencia Colectiva 1

### Autómatas y agentes
- Autómatas celulares: estructura, ej. Juego de la Vida de Conway
- Agentes: qué es, qué debe tener un agente inteligente
- Sistemas multiagente

### Inteligencia colectiva — generalidades
- Denominaciones y características: auto-organización, estigmergia, comportamiento
  emergente, componentes estocásticas, bio-inspiración

### Computación Evolutiva: Algoritmos Genéticos
- Ejemplo de la jirafa (Darwin): variación y selección natural
- La evolución como algoritmo: poblaciones vs. individuos, aleatoriedad, diversidad
- Los 5 elementos de un algoritmo evolutivo: representación, fitness, selección,
  operadores, reproducción
- Genotipo y fenotipo: cromosomas, genes, alelos; codificación y decodificación
- Función de aptitud (fitness): monotonicidad, precisión, suavidad regulable
- Estrategias de selección: ruleta y ventanas
- Operadores de variación: mutación y cruza (exploración vs. explotación)
- Qué pasa con demasiada mutación / demasiada cruza
- Reproducción y reemplazo generacional

### Computación Evolutiva: Variantes
- Estrategias de Evolución: representación fenotípica, (μ+λ)-ES vs. (μ,λ)-ES
- Representación de individuos: genético (binario) vs. evolutivo (real)
- Programación Genética: elementos, representación en árbol, cruza y mutación, manejo de
  restricciones (5 formas)
- Algoritmos multiobjetivo

## UNIDAD 6 — Inteligencia Colectiva 2

### Colonia de Hormigas (ACO)
- Inspiración biológica: estigmergia, experimento del puente binario
- Definiciones formales: grafo, σij, N_i, p^k(t)
- Algoritmo sACO: fórmula de probabilidad, manejo de ciclos
- Algoritmo AS: heurística (η=1/d), lista tabú, formas de depositar feromonas
- α y ρ: qué controla cada uno, comportamiento en los extremos

### Enjambre de Partículas (PSO)
- Inspiración biológica y definiciones: x_k(t), v_k(t), y_k, ŷ
- Fórmulas de velocidad y posición
- gBest vs. lBest: topología y ŷ
- Ventajas y desventajas (convergencia vs. resistencia a óptimos falsos)

## UNIDAD 7 — Lógica Borrosa

### Introducción
- Qué es la lógica borrosa
- Incerteza vs. aleatoriedad: diferencia y ejemplos

### Conceptos matemáticos borrosos
- Conjunto binario vs. conjunto borroso: función de membresía
- Subconjunto borroso: definición formal, inclusión, igualdad, complemento
- Operadores borrosos y geometría de los conjuntos borrosos
- Entropía borrosa

### Memorias Asociativas Borrosas (FAM)
- Qué son: regla simple (local FAM) vs. composición de reglas (global FAM)
- Codificación: Fuzzy Hebb FAMs (correlación-mínimo, correlación-producto)
- Composición de reglas: superposición de matrices vs. Modelo Aditivo Estándar (SAM)
- Defuzzyfication: maximum vs. centroid (ejemplo del semáforo)
- Extensiones de FAM: membresía continua, dos antecedentes por consecuente
