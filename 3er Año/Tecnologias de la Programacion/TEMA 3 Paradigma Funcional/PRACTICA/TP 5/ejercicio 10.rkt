;10. Definir la función resta-listas que devuelve una lista con los elementos de la
;primera lista que no aparecen en la segunda.
;(resta-listas ’(1 2 3 4) ’(2 3)) → (1 4)
(define estaenlalista
  (lambda (elem list)
    (if (null? list)
        #f
        (if (equal? elem (car list))
            #t
            (estaenlalista elem (cdr list))
            )
        )
    )
  )
(estaenlalista '5 '(1 2 3 4))


(define resta-listas
  (lambda (list1 list2)
    (if (null? list1)
        '()
        (if (estaenlalista (car list1) list2)
            (resta-listas (cdr list1) list2)
            (cons (car list1) (resta-listas (cdr list1) list2))
            )
        )
    )
  )
(resta-listas '(1 2 3 4) '(2 3))