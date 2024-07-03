#|
Dada una lista de fuentes de alimentos distribuídos en la plaza, se desea obtener cual de ellos
es el que ofrece menor relación alimento/riegos. Para estimar la riesgo se debe tener en cuenta
la distancia al alimento. El riesgo se calculará con la siguiente fórmula:

Riesgo:
dist < 1m --> 0.1 * dist.
	
1m <= dist < 3m --> 0.3 * dist.
	
3m <= dist --> 0.5 * dist.

Los alimentos se encuentran en una lista de vectores donde sus componentes son (X Y A)
y que es como la siguiente:

(list '(1 1 500)
'(2 4 1500)
'(5 7 7500)
...
)

El hormiguero se encuentra en (0 0).
|#

(define cuadrado
  (lambda (x)
    (* x x)
    )
  )
(define distance-2d
  (lambda (x1 x2 y1 y2)
    (sqrt (+ (cuadrado (- x2 x1)) (cuadrado (- y2 y1))))
    )
  )

(define riesgo
  (lambda (distancia)
    (if (< distancia 1)
        (* 0.1 distancia)
        (if (< distancia 3)
            (* 0.3 distancia)
            (* 0.5 distancia)
            )
        )
    )
  )

(define relacion-alimento-riesgo
  (lambda (list)
    (letrec ((distancia (distance-2d 0 (car list) 0 (car (cdr list)))) (r (riesgo distancia)) (relacion (/ (car (cdr (cdr list))) r)))
      relacion
      )
    )
  )
(relacion-alimento-riesgo '(1 1 500))
(relacion-alimento-riesgo'(2 4 1500))
(relacion-alimento-riesgo'(5 7 7500))

(define comida
  (lambda (lista)
    (if (null? lista)
        '()
        (cons (relacion-alimento-riesgo (car lista)) (comida (cdr lista)))
        )
    )
  )
(comida (list '(1 1 500) '(2 4 1500) '(5 7 7500)))

(define menor
  (lambda (lista)
    (cond
      [(null? lista) null]
      [(null? (cdr lista)) (car lista)]
      [(< (car lista) (cadr lista)) (menor (cons (car lista) (cddr lista)))]
      [else (menor (cdr lista))]
      )
    )
  )

(define riesgo-comida
  (lambda (lista)
    (let ( (a (comida lista)))
      (menor a))))
(riesgo-comida (list '(1 1 500) '(2 4 1500) '(5 7 7500)))