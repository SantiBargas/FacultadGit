
"(cons 1 '(2 3))

(define agregar_al_final
  (lambda (x lista)
    (if (null? lista)
        (list x)
        (cons (car lista)(agregar_al_final x (cdr lista)))
        )
    )
  )"

;(agregar_al_final 1 '(2 3 4))

(define agregar_al_principio
  (lambda (x lista)
    (if (null? lista)
        '()
        (cons (car lista)(agregar_al_principio x (cdr lista)))
        )
    )
  )

(cons 5 '(2 3 4))

(agregar_al_principio 5 '(2 3 4))