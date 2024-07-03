;. Definir un predicado que tome tres argumentos: día, mes y año, y devuelva T si es
;una fecha válida.
;(FECHAP 12 12 1986) => #t
;(FECHAP 12 30 1987) => #f
;(FECHAP 31 2 1986) => #f
;(FECHAP 31 11 1876) => #t

(define 31dias ;1 3 5 7 8 10 12
  (lambda (dia mes año)
    (if (and (<= dia 31) (>= dia 1) ( <= mes 12) (>= mes 1) (>= año 1))
        #t
        #f
        )
    )
  )
(define 30dias ; 4 6 9 11
  (lambda (dia mes año)
    (if (and (<= dia 30) (>= dia 1) ( <= mes 12) (>= mes 1) (>= año 1))
        #t
        #f
        )
    )
  )
(define 28dias ;2
  (lambda (dia mes año)
    (if (and (<= dia 28) (>= dia 1) ( <= mes 12) (>= mes 1) (>= año 1))
        #t
        #f
        )
    )
  )

(define FECHAP
  (lambda (dia mes año)
   (if (equal? mes 2)
       (28dias dia mes año)
       (if (and (equal? mes 4) (equal? mes 6) (equal? mes 9) (equal? mes 11))
           (30dias dia mes año)
           (31dias dia mes año)
           )
       )
    )
  )

(FECHAP 12 12 1986) 
(FECHAP 12 30 1987) 
(FECHAP 31 2 1986) 
(FECHAP 31 11 1876)