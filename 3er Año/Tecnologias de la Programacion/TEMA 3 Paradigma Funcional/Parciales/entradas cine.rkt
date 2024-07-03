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
(define eliminar
  (lambda (x list)
    (if (null? list)
        '()
        (if (equal? x (car list))
            (eliminar x(cdr list))
            (cons (car list) (eliminar x (cdr list)))
            )
        )
    )
  )
;1 standard 300 pesos
;2 jubilados 150 pesos
;3 niños 100 pesos

(define count-elem
  (lambda (x lista)
    (if (null? lista)
    0
    (if (eq? (car lista) x)
        (+ 1 (count-elem x (cdr lista)))
        (count-elem x (cdr lista))
        ) ;cierro if
    );cierro 2if
    );cierro lambda
  )


(define calcularmonto
  (lambda (x y)
    (* x y)
    )
  )
(define crear-lista
  (lambda (x y)
    (cons x y)
    )
  )

(define calculartotal
  (lambda (lista)
    (let ( (a ( + (calcularmonto 300 (count-elem 1 lista))
        (calcularmonto 150 (count-elem 2 lista))
        (calcularmonto 100 (count-elem 3 lista))
        )))
      (cons "total" a)
    )
  )
  )
(calculartotal '(0 0 0 1 1 0 2 0 1 0 0 1 1 3 0 0 1 1 1 1 1 1 1 3 3 1 1 1 0 2 1 1 2 2 0 0 1 1 1 0))

(define factura-cineaux
  (lambda (x y lista)
    (let ( (a  (count-elem x lista)))      
      (crear-lista 1 (calcularmonto a y))
      )
    )
  )   
   
(define factura-cine
  (lambda (lista)
    (let ( (a (APLANAR lista)))
      (list(factura-cineaux 1 300 a)
           (factura-cineaux 2 150 a)
           (factura-cineaux 3 100 a)
           (calculartotal a        ))
    )
  )
  )




      
     
(calcularmonto 300 20)
;(crear-lista 1 6000)
;(APLANAR'((0 0 0 1 1 0 2 0 1 0)(0 1 1 3 0 0 1 1 1 1)(1 1 1 3 3 1 1 1 0 2)(1 1 2 2 0 0 1 1 1 0)))
;(eliminar 1 '(0 0 0 1 1 0 2 0 1 0 0 1 1 3 0 0 1 1 1 1 1 1 1 3 3 1 1 1 0 2 1 1 2 2 0 0 1 1 1 0))
(factura-cine '((0 0 0 1 1 0 2 0 1 0)(0 1 1 3 0 0 1 1 1 1)(1 1 1 3 3 1 1 1 0 2)(1 1 2 2 0 0 1 1 1 0)))
