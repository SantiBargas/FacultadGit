(define contarEquipo
  (lambda (nombre lista)
    (if (null? lista)
        0
        (letrec ( (a (car(car(car lista)))) (b (car(car(cdr(car lista))))))
        (if (equal? a nombre)
            (+ 1 (contarEquipo nombre (cdr lista)))
            (if (equal? b nombre)
                (+ 1 (contarEquipo nombre (cdr lista)))
                (contarEquipo nombre (cdr lista))
                ))))))
;(contarEquipo 'Brasil '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )( (Brasil . 2) (Ecuador . 1) )))  
;(car(car(car '(( (Argentina . 5) (Brasil . 0 )) ((Argentina . 3) (Bolivia . 2) )))))
;(car(car(cdr(car'(( (Argentina . 5) (Brasil . 0 )) ((Argentina . 3) (Bolivia . 2) ))))))


(define eliminarEquipos
  (lambda (nombre1 nombre2 lista)
    (if (null? lista)
        '()
        (letrec ( (a (car(car(car lista)))) (b (car(car(cdr(car lista))))))
        (if (or (equal? nombre1 a) (equal? nombre1 b))
            (eliminarEquipo nombre1 nombre2 (cdr lista))
          (if (or (equal? nombre2 a) (equal? nombre2 b))
               (eliminarEquipo nombre1 nombre2 (cdr lista))
               (cons (car lista) (eliminarEquipo nombre1 nombre2 (cdr lista)))
               ))))))

(define eliminarEquipo
  (lambda (nombre lista)
    (if (null? lista)
        '()
        (letrec ( (a (car(car(car lista)))) (b (car(car(cdr(car lista))))))
        (if (or (equal? nombre a) (equal? nombre b))
            (eliminarEquipo nombre (cdr lista))
            (cons (car lista) (eliminarEquipo nombre(cdr lista))))))))

;(eliminarEquipo 'Brasil '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )))


(define esta-en-la-lista
  (lambda (nombre lista)
    (if (null? lista)
        #f
        (if (equal? (car lista) nombre)
            #t
            (esta-en-la-lista nombre (cdr lista))))))
;(esta-en-la-lista 'Argentina '(Peru Brasil Colombia))

(define lista-equipos
       (lambda (lista)
         (if (null? lista)
             '()
             (cons (car (car (car lista))) (cons (car (car (cdr (car lista)))) (lista-equipos (cdr lista))))
             )
         )
       )

(lista-equipos '( ( (Argentina . 5) (Brasil . 0 ) )( (Argentina . 3) (Bolivia . 2) )( (Argentina . 2) (Chile . 1) )( (Bolivia . 1) (Paraguay . 0) )( (Brasil . 1) (Venezuela . 0) )( (Colombia . 0) (Ecuador . 2) )))

(define eliminar
  (lambda (e lista)
    (if (null? lista)
        '()
        (if (eqv? (car lista) e)
            (eliminar e (cdr lista))
            (cons (car lista) (eliminar e (cdr lista)))
            )
        )
    )
  )
(define unicos
  (lambda (lista)
    (if (null? lista)
        '()
        (cons (car lista) (unicos (eliminar (car lista) lista)))
        )
    )
  )
(unicos '(Argentina Brasil Argentina Bolivia Argentina Chile Bolivia Paraguay Brasil Venezuela Colombia Ecuador))

(define copaAmericaAux
  (lambda (listequipos listresultados)
    (if (null? listequipos)
        '()
        (cons (cons (car listequipos) (contarEquipo (car listequipos) listresultados)) (copaAmericaAux (cdr listequipos) listresultados))
        )
    )
  )

(define copaAmerica
  (lambda (lista)
    (if (null? lista)
        '()
        (copaAmericaAux (unicos (lista-equipos lista)) lista)
        )
    )
  )

(copaAmerica '( ( (Argentina . 5) (Brasil . 0 ) )
( (Argentina . 3) (Bolivia . 2) )
( (Argentina . 2) (Chile . 1) )
( (Bolivia . 1) (Paraguay . 0) )
( (Brasil . 1) (Venezuela . 0) )
( (Colombia . 0) (Ecuador . 2) )
( (Brasil . 2) (Ecuador . 1) )
))