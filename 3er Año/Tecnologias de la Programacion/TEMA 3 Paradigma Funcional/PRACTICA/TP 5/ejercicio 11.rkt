;11. Definir la función suma-listas que devuelve una lista con los elementos de la
;primera lista y los de la segunda que no aparecen en la primera.
;(suma-listas ’(1 2 3 4) ’(2 3 5)) → (1 2 3 4 5)

(define concatenar
  (lambda (list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (concatenar (cdr list1) list2))
        )
    )
  )
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

(define suma-listas
  (lambda (list1 list2)
    (if (null? list2)
         list1
        (if(estaenlalista (car list2) list1)
           (suma-listas list1 (cdr list2))
           (cons (car list2) (suma-listas list1 (cdr list2)))
           )
        )
    )
  )

         
(suma-listas '(1 2 3 4) '(2 3 5))