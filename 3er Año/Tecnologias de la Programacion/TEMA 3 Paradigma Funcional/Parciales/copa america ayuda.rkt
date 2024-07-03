(define eliminarEquipo
  (lambda (nombre1 nombre2 lista)
    (if (null? lista)
        '()
        (letrec ( (a (car(car(car lista)))) (b (car(car(cdr(car lista))))))
        (if (or (equal? nombre1 a) (equal? nombre1 b))
            (eliminarEquipo nombre1 nombre2 (cdr lista))
          (if (or (equal? nombre2 a) (equal? nombre2 b))
               (eliminarEquipo nombre1 nombre2 (cdr lista))
               (cons (car lista) (eliminarEquipo nombre1 nombre2 (cdr lista)))
               )
          )
          )
        )
    )
  )
               
            
  

;(eliminarEquipo 'Brasil 'Argentina '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) )))


