;2. Definir un predicado con tres argumentos: un átomo y dos listas. El predicado debe
;devolver T si el átomo pertenece a las dos listas.
;(pertenece 'a '(a b c) '(r f g a)) → #t
;(pertenece 'a '(a b c) '(r f g h)) → #

(define pertenece
  (lambda (atomo list1 list2)
    (if (null? list1)
        #f
        (if (equal? atomo (car list1))
            (if (null? list2)
                #f
                (if (equal? atomo (car list2))
                    #t
                    (pertenece atomo list1 (cdr list2))
                    )
                )  ;hasta aca comparo si es verdadero en la primer lista
            (pertenece atomo (cdr list1) list2)
            )
        )
    )
  )
(pertenece 'a '(a b c) '(r f g a))
(pertenece 'a '(a b c) '(r f g))

; UNA FORMA MAS FACIL USANDO EL PERTENECE COMO FUNCION AUXILIAR

(define perteneceAux
  (lambda (atomo list1)
    (if (null? list1)
        #f
        (if (equal? atomo (car list1))
            #t
            (perteneceAux atomo (cdr list1))
            )
        )
    )
  )

(define pertenece2
  (lambda (atomo list1 list2)
    (if (perteneceAux atomo list1)
        (if (perteneceAux atomo list2)
            #t
            #f
            )
        )
    )
  )
(pertenece2 'a '(a b c) '(r f g a))
(pertenece2 'a '(a b c) '(r f g))