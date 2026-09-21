# Dudas para preguntarle al profesor

Preguntas que surgen durante la preparación y que conviene chequear con el profesor
(Milone) o los colaboradores, porque no quedan 100% cerradas solo con los PDFs/resúmenes.

---

## [2026-08-24] Regla delta con función de activación no lineal (signo / sigmoidea)

**Contexto:** derivamos la regla delta para el perceptrón simple asumiendo salida lineal,
es decir `y(n) = ⟨w(n),x(n)⟩` sin función de activación de por medio (φ = identidad):

```
w(n+1) = w(n) − η∇_w ξ(n) = w(n) − η(−2e(n)x(n)) = w(n) + 2η e(n) x(n)
```

**Duda:** ¿cómo cambia el desarrollo (la derivada) si la salida pasa antes por una función
de activación no lineal φ? En particular:

- **Función signo** (la del perceptrón clásico de Rosenblatt): no es derivable en 0 y su
  derivada es 0 en el resto de los puntos — ¿por qué entonces el perceptrón simple clásico
  no usa descenso por gradiente para entrenarse con esta activación? ¿Qué regla usa en su
  lugar y cómo se relaciona con la regla delta que sí sale de minimizar el error cuadrático?
- **Función sigmoidea** (la que se usa en backpropagation / MLP): ¿dónde entra exactamente
  la derivada `φ'(v)` en la regla de la cadena? ¿Queda algo tipo
  `∇_w ξ(n) = −2 e(n) φ'(v(n)) x(n)`, con `v(n) = ⟨w(n),x(n)⟩` el potencial de activación
  antes de pasar por φ?

**Por qué importa:** es la bisagra entre "perceptrón simple con salida lineal" (unidad 2) y
"backpropagation / MLP" (unidad 3) — entender bien ese paso intermedio evita trabarse si el
profesor pide ampliar de uno a otro en el oral.
