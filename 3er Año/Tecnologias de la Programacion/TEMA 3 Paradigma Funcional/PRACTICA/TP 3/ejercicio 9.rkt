;9. Defina un procedimiento en Racket que reciba como parámetros una lista de pares que 
;representan puntos en el plano y devuelva una lista de las distancias entre cada uno de 
;ellos tomados de a pares secuencialmente (distancia entre el primero y el segundo, 
;luego entre el segundo y el tercero, y así sucesivamente).
;(distancias '((1 . 1) (1 . 2) (2 . 2) (2 . 1) (1 . 1)) -->  (1 1 1 1)

;Para sacar distancias con listas improbias
(define cuadrado
  (lambda(a)
    (* a a)
    )
  )


(define distanced
  (lambda (p1 p2)
    (let((x1 (car p1)) (x2 (car p2)) (y1 (cdr p1)) (y2(cdr p2)))
      (sqrt (+ (cuadrado(- x2 x1)) (cuadrado(- y2 y1))))
      )
    )
  )

;Para ver si la lista es impropia
(define distance2d
  (lambda (p1 p2)
    (if(or (list?(cdr p1)) (list?(cdr p2)))
       "No paso listas Impropias"
          (let( (x1 (car p1)) (y1 (cdr p1)) (x2 (car p2)) (y2 (cdr p2)))
      (let ((a (- x2 x1)) (b (- y2 y1)))
        (sqrt ( + (* a a) (* b b)))
        )
      )
    )
  )
 )



(define distancias
  (lambda (lista)
    (if (null? (cdr lista))
        '()
        (let ((p1 (car lista)) (p2 (car (cdr lista))))
         (cons (distanced p1 p2)
               (distancias (cdr lista))
               )
          )
        )
    )
  )
       
 (distancias '((1 . 1) (1 . 2) (2 . 2) (2 . 1) (1 . 1)))