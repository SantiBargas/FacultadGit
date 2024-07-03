(define largo
 (lambda (ls)
 (if (null? ls)
      0
 (+ (largo (cdr ls)) 1)
   )
))


(define corto
  (lambda (a b)    ;a = b = lista de lista
   (if(and (list? a) (list? b))  ;preguntamos si a y b son unas listas
      (if (> (largo a) (largo b)) ;sacamos que lista es mayor
          b                         ;si a>b devolvemos b q es mas chico, si b>a o b=a devolvemos a
          a
          )
      ("NO ES UNA LISTA")
      )
    )
  )

(corto '(a b) '(c d e))