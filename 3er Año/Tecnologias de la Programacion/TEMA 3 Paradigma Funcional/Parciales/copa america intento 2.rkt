
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
;(APLANAR '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) )))
;(car(APLANAR '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) ))))

(define contarEquipo
  (lambda (equipo lista)
    (if (null? lista)
        0
        (let ( (a (car (car lista))))
          (if (equal? a equipo)
              (+ 1 (contarEquipo equipo (cdr lista)))
              (contarEquipo equipo (cdr lista)))))))
;(contarEquipo 'Argentina (APLANAR'( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) ))))

(define eliminarEquipo
  (lambda (nombre lista)
    (if (null? lista)
        '()
        (letrec ( (a (car(car lista))))
        (if (equal? nombre a)
            (eliminarEquipo nombre (cdr lista))
            (cons (car lista) (eliminarEquipo nombre(cdr lista))))))))

;(eliminarEquipo 'Argentina (APLANAR'( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) ))))

(define contarPartidosAUX
  (lambda (lista)
    (if (null? lista)
        '()
        (let ( (a (car(car lista))))
          (cons a (contarEquipo a lista))
          )
        )
    )
  )
;(contarPartidosAUX(APLANAR '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) ))))


(define contarPartidos2
  (lambda (lista)
    (if (null? lista)
        '()
        (let ( (a (car (car lista))))
          (cons (contarPartidosAUX lista) (contarPartidos2 (eliminarEquipo a lista)))
          )
        )
    )
  )

(define contarPartidos
  (lambda (lista)
    (contarPartidos2 (APLANAR lista))
    )
  )
      
(contarPartidos '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) )))
