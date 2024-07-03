;1. Crear una función que concatene L1 con el inverso de L2.
;(conctat-inv '(1 2 3) '(4 5 6)) → '(1 2 3 6 5 4)

(define concatenar
  (lambda (list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (concatenar (cdr list1) list2))
        )
    )
  )

(concatenar '(1 2 3) '(4 5 6))

(define inverso
  (lambda (lista)
    (if (null? lista)
        '()
        (concatenar (inverso (cdr lista)) (list (car lista)))
        )
    )
  )
(inverso '(1 2 3))

(define conctat-inv
 (lambda (list1 list2)
   (concatenar list1 (inverso list2))
   )
  )

(conctat-inv '(1 2 3) '(4 5 6))

