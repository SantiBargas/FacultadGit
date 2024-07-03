(define concatenar
  (lambda (list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (concatenar (cdr list1) list2))
        )))
(define APLANAR
  (lambda (ls)
    (if (null? ls)
        '()
        (if (list? (car ls))
            (concatenar (APLANAR (car ls)) (APLANAR (cdr ls)))
            (cons (car ls) (APLANAR (cdr ls)))
            ))))

;(APLANAR '((0 0 0 1 1 0 2 0 1 0)(0 1 1 3 0 0 1 1 1 1)(1 1 1 3 3 1 1 1 0 2)(1 1 2 2 0 0 1 1 1 0)))

(define count-elem
  (lambda (x lista)
    (if (null? lista)
    0
    (if (eq? (car lista) x)
        (+ 1 (count-elem x (cdr lista)))
        (count-elem x (cdr lista))))))
;(count-elem 1 '(0 0 0 1 1 0 2 0 1 0 0 1 1 3 0 0 1 1 1 1 1 1 1 3 3 1 1 1 0 2 1 1 2 2 0 0 1 1 1 0))

(define calcularAsiento
  (lambda (x cantidad)
    (if (equal? x 1)
        (* cantidad 300)
        (if (equal? x 2)
            (* cantidad 150)
            (if (equal? x 3)
                (* cantidad 100)
                )))))
;(calcularAsiento 2(count-elem 2 '(0 0 0 1 1 0 2 0 1 0 0 1 1 3 0 0 1 1 1 1 1 1 1 3 3 1 1 1 0 2 1 1 2 2 0 0 1 1 1 0)))

(define eliminar
  (lambda (x list)
    (if (null? list)
        '()
        (if (equal? x (car list))
            (eliminar x(cdr list))
            (cons (car list) (eliminar x (cdr list)))
            ))))
;(eliminar 0 '(0 0 0 1 1 0 2 0 1 0 0 1 1 3 0 0 1 1 1 1 1 1 1 3 3 1 1 1 0 2 1 1 2 2 0 0 1 1 1 0))

(define calcularTotal
  (lambda (lista)
   (if (null? lista)
       0
    (if (equal? (car lista) 1)
        (+ (calcularAsiento (car lista) (count-elem (car lista) lista))(calcularTotal (eliminar (car lista) lista)))
        (if (equal? (car lista) 2)
           (+ (calcularAsiento (car lista) (count-elem (car lista) lista)) (calcularTotal (eliminar (car lista) lista)))
           (if (equal? (car lista) 3)
               (+ (calcularAsiento (car lista) (count-elem (car lista) lista))(calcularTotal (eliminar (car lista) lista)))
               (calcularTotal (cdr lista))))))))
(define crearTotal
  (lambda (lista)
    (cons "total" (calcularTotal lista))
    )
  )
;(crearTotal '(0 0 0 1 1 0 2 0 1 0 0 1 1 3 0 0 1 1 1 1 1 1 1 3 3 1 1 1 0 2 1 1 2 2 0 0 1 1 1 0))


(define entradaCineAux
  (lambda (lista)
        (cons (car lista) (calcularAsiento (car lista) (count-elem (car lista) lista)))
        )
    )
(define entradaCine2
 (lambda (lista1 lista2)
   (if (null? lista1)
       (list lista2)
       (cons (entradaCineAux lista1) (entradaCine2 (eliminar (car lista1) lista1) lista2))
       )
   )
  )

(define entradaCine
  (lambda (lista)
    (let ( (a (APLANAR lista)))
     (entradaCine2 (eliminar 0 a) (crearTotal a))
      )
    )
  )
  

(entradaCine '((0 0 0 1 1 0 2 0 1 0)(0 1 1 3 0 0 1 1 1 1)(1 1 1 3 3 1 1 1 0 2)(1 1 2 2 0 0 1 1 1 0)))

           

