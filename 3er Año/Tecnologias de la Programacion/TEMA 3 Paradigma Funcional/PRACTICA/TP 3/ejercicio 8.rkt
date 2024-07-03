;. Se desea crear un programa que permita convertir un lote de datos de un formato a otro.
;Los datos llegan en formato de lista de listas, donde el primer elemento determina el 
;contenido de la lista y el segundo tiene la lista de datos. Los datos pueden venir en 
;formato texto, decimal o booleano y se desea obtener una lista igual pero con todos sus 
;componentes en formato decimal y todos positivos.
;Ej:
;      (conv­datos '(
;            ("D" (1 2 ­-3 4 -­5))
;            ("T" ("6" "7" "8"))
;            ("B" ("V" "F"))
;       )   ­­­­­­­­­­­­­             --------> '((1 2 3 4 5) (6 7 8) (1 0))


(define convertirdecimal
  (lambda (list)
    (if (null? list)
       '()
        (cons (abs (car list)) (convertirdecimal(cdr list)))
        )
    )
  )

(define convertirtexto
  (lambda (list)
    (if(null? list)
       '()
        (cons (string->number(car lista)) (conv-T (cdr lista)))
        )
    )
  )

(define tOf
  (lambda(x)
    (if (equal? x "V")
        1
        0
        )
    )
  )

(define convertirbool
  (lambda(lista)
        (if(null? lista)
           lista
           (cons (tOf ( car lista)) (convertirbool (cdr lista)))
           )
        )
  )


(define convdatos
  (lambda (lista)
    (if (equal? (car (car lista)) "D")
        (convertirdecimal (cdr lista))
        (if (equals? (car (car lista))"T")
            (convertirtexto (cdr lista))
            (if (equals? (car (car lista)) "B")
                (convertirbool (cdr lista))
                )
            )
        )
    )
  )


