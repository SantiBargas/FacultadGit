;Escriba en Racket el procedimiento (concatenar l1 l2) que recibe dos listas l1 y l2 como 
;argumento y retorna una única lista que contiene primero todos los elementos de l1 
;seguido de todos los elementos de l2 (no puede usar el procedimiento interno append 
;que viene en algunas implementaciones de Racket)

;Concatenar dos listas
(define concatenar
  (lambda (l1 l2)
    (if (null? l1)
        l2
        (cons (car l1) (concatenar (cdr l1) l2))
            )
        )
    )
  


(concatenar '(a b c) '(d e f))