;7. Defina un procedimiento en Racket llamado attach-at-end que reciba como parámetro
;un valor y una lista y retorne la lista con los mismos valores excepto el que se pasó por
;parámetro que se agregará al final.
;(attach-at-end 'prueba '(esto es una)) (esto es una prueba)

(define eliminar   ;;esto es una
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

(define attach-at-end
  (lambda (valor lista)
    (letrec ((listaux (eliminar valor lista)))
    (if (null? lista)
        (cons valor lista)
        (attach-at-end valor (cdr lista))
        )
      (cons listaux lista)
    )
  )
 )

(define attach
  (lambda (e l)
         (if (null? l)
             (cons e ())
             (let ((p (car l)) (q (cdr l)))
               (cons p (attach-at-end e q))
               )
             )
         )
  )
  
;(eliminar 'prueba '(esto es prueba una prueba))
;(attach-at-end 'prueba '(esto es una))
(attach 'prueba '(esto es una))