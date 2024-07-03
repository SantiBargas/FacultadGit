;Definir una función APLANAR que reciba como argumento una expresión simbólica
;y elimine todos los paréntesis que aparezcan en esa expresión, devolviendo como
;resultado una lista con todos los átomos que aparezcan en el argumento.
;(APLANAR ‘( (1 2 3) (9 (2 3 4) ) ( ( ( ( 3 4 ( 7 ) ) ) ) ) ) ) → ( 1 2 3 9 2 3 4 3 4 7 )

(define concatenar
  (lambda (list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (concatenar (cdr list1) list2))
        )
    )
  )
(define APLANAR
  (lambda (ls)
    (if (null? ls)
        '()
        (if (list? (car ls))
            (concatenar (APLANAR (car ls)) (APLANAR (cdr ls)))
            (cons (car ls) (APLANAR (cdr ls)))
            )
        )
    )
  )


(APLANAR '( (1 2 3) (9 (2 3 4) ) ( ( ( ( 3 4 ( 7 ) ) ) ) ) ) )        