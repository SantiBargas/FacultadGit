(define largo
 (lambda (ls)
 (if (null? ls)
      0
 (+ (largo (cdr ls)) 1)
   )
))


(largo '(a b c d))

(define extraer_elemento
  (lambda (pos lista)
    (if (null? lista)
        "No se encuentra el elemento"
        (if (equal? pos 