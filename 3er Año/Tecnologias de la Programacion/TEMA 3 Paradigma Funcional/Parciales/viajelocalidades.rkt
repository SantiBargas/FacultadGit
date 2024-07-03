(define tarifa '(
                 ("Santa Fe" 5 ((10.0)(12.0)(16.0)))
                 ("Recreo" 2 ((10.20)(12.20)(16.20)))
                 ("Candiotti" 1 ((10.30)(12.30)(16.30)))
                  ("Iriondo" 2 ((10.35)(12.35)(16.35)))
                   ("Manucho" 2 ((10.45)(12.45)(16.45)))
                    ("Cululu" 0 ((11.0)(13.0)(17.0)))
                    ))



;(car(car tarifa)) ;Santa fe
;(car(cdr(car tarifa))) ;5
;(car(cdr(cdr(car tarifa)))) ; ((10.0) (12.0) (16.0))
;(cdr tarifa)
(define eliminarLocalidad
  (lambda (localidad lista)
        (if (null? lista)
        '()
        (if (equal? (car(car lista)) localidad)
            (cons (car lista) (cdr lista))
            (eliminarLocalidad localidad (cdr lista))
        )
    )
  )
  )

(define BuscarPrecio
  (lambda (localidad1 localidad2 lista)
    (if (null? lista)
        "No se encontro la localidad"
        (if (equal? localidad1 (car(car lista)))
            (+ (car(cdr(car lista))) (BuscarPrecio localidad1 localidad2 (cdr lista)))
            (if (equal? (car(car lista)) localidad2)
                0
                (+ (car(cdr(car lista))) (BuscarPrecio localidad1 localidad2 (cdr lista)))
                )
            )
        )
    )
  )        
(BuscarPrecio "Recreo" "Manucho" (eliminarLocalidad "Recreo" tarifa))


(define BuscarHorarioAux
  (lambda (hora list)
    (if (null? list)
        '()
        (if (<= (car hora) (car(car list)))
            (cons (car list) (BuscarHorarioAux hora (cdr list)))
            (BuscarHorarioAux hora (cdr list))
            )
        )
    )
  )
;(BuscarHorarioAux '(12.30) '((10.0) (12.0)(16.0)))
    
(define BuscarHorario
  (lambda (localidad hora list)
    (if (null? list)
        "No hay horarios disponibles"
        (if (equal? localidad (car(car list)))
            (BuscarHorarioAux hora (car(cdr(cdr(car tarifa)))))
            (BuscarHorario localidad hora (cdr list))
            )
        )
    )
  )
(BuscarHorario "Santa Fe" '(12.30) tarifa)
(BuscarHorario "Recreo" '(12.30) tarifa)
(BuscarHorario "Recreo" '(9) tarifa)
    
(define viaje
  (lambda (origen destino hora)
    (let ( (c (BuscarPrecio origen destino (eliminarLocalidad origen tarifa))) (d (BuscarHorario origen hora tarifa)) )
      (list origen destino c '$ (car(car d)) )
      )
  )
  )

(viaje "Recreo" "Manucho" '(12.30))
(viaje "Santa Fe" "Cululu" '(12.30))
(viaje "Santa Fe" "Iriondo" '(12.30))