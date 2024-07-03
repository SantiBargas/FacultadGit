;3. Definir una función que devuelva el número de átomos que hay en una lista
;situados a la izquierda de un átomo determinado de dicha lista.
;(cant-izq 'd '(a b c d e f)) → 3"

(define contarelementos
  (lambda (list)
  (if (null? list)
      0
      (+ 1 (contarelementos(cdr list)))
      )
    )
  )

(define cant-izq
 (lambda (atomo list)
   (if (null? list)
       "la lista no contiene al atomo"
       (if (equal? atomo (car list))
           (contarelementos  list)
           (cant-izq atomo (cdr list))
           )
       )
   )
 )

(cant-izq 'd '(a b c d e f))
               
                   