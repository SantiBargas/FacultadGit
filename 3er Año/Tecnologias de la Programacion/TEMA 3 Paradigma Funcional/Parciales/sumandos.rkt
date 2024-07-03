(define largo
 (lambda (ls)
 (if (null? ls)
      0
 (+ (largo (cdr ls)) 1)
   )
))
(define par
  (lambda (x)
    (if (even? x)
        #t
        #f
        )
    )
  )
(define dividir
  (lambda (A)
    (if (equal? A 1)
        '(1)
        (cons A (dividir (floor (/ A 2))))
        )
    )
  )      
;(dividir 27)

(define multiplicar
  (lambda(lista B cont)
    (if (equal? cont (largo lista))
        '()
        (cons B (multiplicar lista (* B 2) (+ 1 cont)))
        )
    )
  )
;(multiplicar (dividir 27) 82 0)

(define sumandos
  (lambda (listA listB)
    (if (null? listA)
        '()
        (if (par (car listA))
             (sumandos(cdr listA) (cdr listB))
            (cons (car listB) (sumandos(cdr listA) (cdr listB)))
           )
        )
    )
  )
;(sumandos (dividir 27) (multiplicar (dividir 27) 82 0))

(define sumar
  (lambda (lista)
    (if (null? lista)
        0
        (+ (car lista) (sumar(cdr lista)))
        )
    )
  )

;(sumar (sumandos (dividir 27) (multiplicar (dividir 27) 82 0)))

;WRAPPER
(define wrapper
  (lambda (x y)
    (let ( (a (dividir x)))
      (let ( (b (multiplicar a y 0)))
       (let ( (c (sumandos a b)))
         (sumar c))
      )
    )
  )
 )
(wrapper 27 82)

