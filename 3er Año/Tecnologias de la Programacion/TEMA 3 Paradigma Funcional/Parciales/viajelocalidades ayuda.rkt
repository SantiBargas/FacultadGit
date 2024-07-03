(define tarifa '(
                 ("Santa Fe" 5 ((10.0)(12.0)(16.0)))
                 ("Recreo" 2 ((10.20)(12.20)(16.20)))
                 ("Candiotti" 1 ((10.30)(12.30)(16.30)))
                  ("Iriondo" 2 ((10.35)(12.35)(16.35)))
                   ("Manucho" 2 ((10.45)(12.45)(16.45)))
                    ("Cululu" 0 ((11.0)(13.0)(17.0)))
                    ))

(define eliminarLocalidad
  (lambda (localidad lista)
        (if (null? lista)
        '()
        (if (equal? (car(car lista)) localidad)
            (eliminarLocalidad localidad (cdr lista))
            (cons (car lista)(eliminarLocalidad localidad (cdr lista)))
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

(BuscarPrecio "Recreo" "Manucho"  tarifa)

(car(car tarifa)) ;Santa fe
(car(cdr(car tarifa))) ;5
(car(cdr(cdr(car tarifa)))) ;((10.0) (12.0) (16.0))
(car(car(cdr(cdr(car tarifa)))));(10.0)
(cdr(car(cdr(cdr(car tarifa))))) ;((12.0) (16.0))

(define mayorImpropia
  (lambda (hora list)
    (if (null? list)
        '()
        (if (< (car hora) (car(car list)))
            (cons (car list) (mayorImpropia hora (cdr list)))
            (mayorImpropia hora (cdr list))
            )
        )
    )
  )
(mayorImpropia '(12.30) '((10.0) (12.0)(16.0)))



;LISTA = ((10.0) (12.0) (16.0))





