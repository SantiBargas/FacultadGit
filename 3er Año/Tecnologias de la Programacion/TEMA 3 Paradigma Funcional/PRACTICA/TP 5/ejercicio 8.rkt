;Definir la función rotar que rota los elementos de una lista hacia la derecha o hacia
;la izquierda.
;(rotar ’derecha ’(1 2 3 4)) → (4 1 2 3)
;(rotar ’izquierda ’(1 2 3 4)) → (2 3 4 1)

(define agregar_al_final
  (lambda (x lista)
    (if (null? lista)
        (list x)
        (cons (car lista)(agregar_al_final x (cdr lista)))
        )
    )
  )
;(agregar_al_final 1 '(2 3 4))

(define rotar_izquierda
  (lambda (lista)
    (if (null? lista)
        (list (car lista))
        (agregar_al_final (car lista) (cdr lista))
        )
    )
  )

 (rotar_izquierda '(1 2 3 4))
(rotar_izquierda '(10 15 20 25))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define extraer_elemento
  (lambda (pos listado)
    (letrec ((funcion (lambda (contador posicion lista)
                        (if (null? lista)
                            '()
                            (if (= contador posicion)
                                (cdr lista)
                                (cons (car lista) (funcion (+ contador 1) posicion (cdr lista)))
                                )
                            )
                        )
                      )
             )(funcion 1 pos listado)
      )
    )
  )
(define obtener_elemento (lambda (n lista)
(letrec((devolver_n (lambda (cont n lista)
                      (if (null? lista)
                          "null"
                          (if (= n cont)
                              (car lista)
                              (devolver_n (+ cont 1) n (cdr lista))
                              )
                          )
                      )
                    )
        )(devolver_n 1 n lista)
  )
                           )
  )

(define rotar_derecha
  (lambda (lista)
    (if (null? lista)
        '()
        (cons (obtener_elemento (length lista) lista) (extraer_elemento (length lista) lista))
        )
    )
  )
(rotar_derecha '(1 2 3 4))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


