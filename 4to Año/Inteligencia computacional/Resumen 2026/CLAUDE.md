# Inteligencia Computacional — Preparación oral 2026

Contexto de trabajo para las sesiones de chat mientras se prepara el **examen final oral**
del jueves **17/09/2026** (UNL - FICH, Ingeniería Informática). Ya se rindió una vez hace
~1 mes y medio (nota 5) — esta es una segunda vuelta con mejor enfoque de preparación.

## Diagnóstico de la vez anterior (foco de esta preparación)

1. **Falta de profundidad/justificación**: se sabían las respuestas pero costaba justificar
   el *por qué* o ampliar cuando el profesor repreguntaba.
2. **Trabas con fórmulas/matemática**: el desarrollo preliminar en pizarra (notación,
   fórmulas) costó más que la explicación conceptual.

→ El objetivo no es solo "saber la respuesta", sino poder **derivarla/justificarla** y
**resolverla en papel** sin trabarse.

## Formato del examen (fuente: `IC26 Planificacion presentada a Secretaria Academica
260803.pdf`, en esta misma carpeta)

- Oral, 15–30 min por alumno.
- Se sortean **3 temas**. Para cada uno: desarrollo preliminar en pizarra/papel +
  explicación oral, respondiendo preguntas y ampliaciones que pida el profesor.
- Docente responsable: Milone, Diego Humberto (colaboradores: Di Persia, Vignolo, Vitale,
  Gerard).

## Temario oficial (7 unidades)

1. **Introducción**: revisión histórica, áreas del conocimiento, cerebro humano y límites
   del cálculo computacional, clasificación de técnicas de IC.
2. **Redes neuronales 1**: inspiración biológica, modelos de neurona, funciones de
   activación, **perceptrón simple** (hiperplanos, entrenamiento, limitaciones),
   clasificación de arquitecturas/procesos de aprendizaje.
3. **Redes neuronales 2**: **perceptrón multicapa** (backpropagation, velocidad de
   aprendizaje, momento, criterios de finalización), **RBF-NN**, **SOM** (mapas
   auto-organizativos, cuantización vectorial/LVQ), **redes dinámicas** (Hopfield, BPTT,
   Elman, Jordan).
4. **Aprendizaje automático**: bases estadísticas de reconocimiento de patrones, mínimos
   locales/globales, generalización y validación cruzada, métodos no neuronales (kNN,
   árboles, Naive Bayes, SVM), **ensambles** (bagging, stacking, boosting, AdaBoost,
   gradient boosting), clustering y métricas.
5. **Inteligencia colectiva 1**: autómatas celulares, agentes inteligentes, sistemas
   multiagente, **computación evolutiva** (algoritmos genéticos, programación genética,
   estrategias de evolución, algoritmos multiobjetivo).
6. **Inteligencia colectiva 2**: **colonia de hormigas** (estigmergia, feromonas, ACO),
   **enjambre de partículas** (PSO, gBest/lBest).
7. **Lógica borrosa**: conjuntos borrosos, geometría y operadores borrosos, entropía
   borrosa, **memorias asociativas borrosas** (FAM, codificación y composición de reglas,
   defuzzyfication).

## Cómo se arma el resumen

- **El resumen en sí lo redacta el usuario en Google Docs** (fuera de este repo). Esta
  carpeta y este CLAUDE.md son solo el contexto de apoyo para las sesiones de chat, no el
  documento final.
- Fuentes a combinar/cruzar:
  - **PDFs de teoría de la cátedra**, organizados en carpetas numeradas por bloque temático
    (cada una con subcarpetas `NN - Tema/` que contienen el PDF de esa clase):
    - `../1 Redes neuronales/` → Unidades 2 y 3: `01 - Perceptron Simple/`,
      `02 - Perceptron multicapa/`, `03 - Redes con funciones de base radial/`,
      `04 - Mapas autoorganizativos/`, `05 - Redes neuronales dinamicas/`.
    - `../2 Lógica borrosa/` → Unidad 7: `01 - Lógica borrosa/`,
      `02 - Memorias asociativas borrosas/`.
    - `../3 Inteligencia colectiva/` → Unidades 5 y 6: `01 - Inteligencia colectiva/`,
      `02 - Computacion evolutiva/`, `03 - Variantes de computacion evolutiva/`,
      `04 - Inteligencia de colonias y enjambres/`.
    - `../Otras clases/` → Unidad 4 (Aprendizaje automático) y complementos: Capacidad de
      generalización, Clustering y métricas, Introducción al aprendizaje automático no
      neuronal, Introducción al aprendizaje profundo, Introducción al reconocimiento
      estadístico de patrones, Sistemas basados en el conocimiento.
    - **Unidad 1 (Introducción)** no tiene PDF propio identificado en ninguna de estas
      carpetas — revisar si está en alguna de arriba o si falta conseguirlo.
  - Resúmenes de compañeros ya existentes en `../Resumenes/` (Apuntes IC - Varrone,
    Resumen Tom Cassiet, `Unidad N IC.pdf`, Back propagation, RBF-NN, k-medias, Stacking).
  - Videos de YouTube de teoría: cronograma semanal enviado por el profesor (Diego
    Milone), con códigos de video por semana. Ver `videos_teoria.md` — incluye el canal
    (https://www.youtube.com/@DiegoMilone), el cronograma tal cual lo mandó, y una tabla
    para ir completando a qué tema/unidad corresponde cada código a medida que se miran.
    Ver limitación abajo.
  - `../Resumenes/preguntas_de_repaso.txt` + `../Resumenes/Respuestas_Repaso_U2-U7.pdf`:
    ya existe un cuestionario de repaso ordenado por unidad (**Unidades 2 a 7**, con
    respuestas). Buen punto de partida — **falta Unidad 1** (Introducción), no cubierta ahí.

## Limitación sobre los videos de YouTube

No hay capacidad de "ver" ni "escuchar" un video directamente. Frente a una lista de
videos, la forma de ayudar es: buscar el video por título/canal (WebSearch) y, si tiene
transcripción/subtítulos públicos, intentar leerla (WebFetch) — sin garantía de que el
contenido recuperado sea completo o preciso. Tratar la lista de videos como guía de qué
temas priorizar/complementar, no como fuente principal. La fuente confiable de contenido
son los **PDFs de la cátedra**.

## Cómo trabajar en el chat (rol del asistente)

1. El resumen final lo escribe el usuario en Google Docs; en el chat se discute y explica
   contenido, no se redacta el documento final salvo pedido puntual.
2. Enfocar en **profundidad, no solo la respuesta correcta**: después de cada explicación,
   preguntar el "por qué" y pedir justificación teórica, simulando repreguntas del oral.
3. Practicar el **desarrollo escrito/matemático** de las fórmulas (no solo lo conceptual),
   ya que fue el punto débil detectado — pedir resolver en "papel" (texto/LaTeX en el
   chat) antes de pasar a la siguiente pregunta.
4. Simular ampliaciones tipo oral: el profesor puede pedir "amplíe sobre X" en cualquier
   subtema entregado.
5. Usar `../Resumenes/preguntas_de_repaso.txt` como columna vertebral del repaso; para
   Unidad 1 armar preguntas equivalentes ya que no está cubierta ahí.
6. Cruzar contenido entre PDFs de cátedra + resúmenes de compañeros (+ videos si aportan
   algo) para detectar dónde coinciden y dónde alguien explica distinto o mejor.

## Recursos existentes relevantes

- `../Resumenes/preguntas_de_repaso.txt` — cuestionario Unidades 2–7.
- `../Resumenes/Respuestas_Repaso_U2-U7.pdf` — respuestas a ese cuestionario.
- `../Resumenes/Unidad 2..7 IC.pdf`, `Apuntes IC - Varrone.pdf`, `Resumen Tom Cassiet.pdf`,
  `Back propagation.pdf`, `RBF-NN.pdf`, `k-medias.pdf`, `Stacking.pdf` — resúmenes de
  compañeros por tema/unidad.
- `../Parciales/Parcial 1/` y `../Parciales/Parcial 2/` — parciales y preguntas de años
  anteriores; útil porque el oral puede retomar temas de ahí.
- `../Practica 2026/` — repo de prácticas de esta misma cursada, donde ya se trabaja con
  la lógica de "teoría antes que práctica" y justificar cada decisión de diseño. Mismo
  criterio aplica acá.

## Pendiente / próximos pasos

- [ ] Completar la tabla código→tema de `videos_teoria.md` a medida que se miran los
      videos (confirmar también si la playlist candidata ahí listada es la correcta).
- [x] Estructura de títulos/subtítulos para el Google Docs propuesta en
      `estructura_resumen.md` (7 unidades, con bloques y subtemas). Ajustar ahí si el
      usuario reordena algo al pasarlo a Docs.
- [ ] Armar preguntas de repaso para Unidad 1 (Introducción), no cubierta en
      `preguntas_de_repaso.txt`.
