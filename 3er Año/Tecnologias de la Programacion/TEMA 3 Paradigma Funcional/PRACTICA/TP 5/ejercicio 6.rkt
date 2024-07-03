;6.Definir la función get-profundidad que obtiene el número máximo de listas anidadas
;que aparecen en una lista.
;(get-profundidad ’((1 (2)) (((5 7))) 4)) → 3


(define get-profundidad
  (lambda (lista)
    (if (null? lista)
        0
        (if (not(list? (car lista))) ; Si no es una lista el car
            (if(not(null? (cdr lista)))
               (get-profundidad (cdr lista))
               0
               )
           (let((pri_elem (+ 1 (get-profundidad (car lista))))
                (resto (get-profundidad (cdr lista))))  ;Si el car es una lista
                  (if (> pri_elem resto)
                      pri_elem
                      resto
                      )
                  )
              )
            )
        )
    )
 
  

(get-profundidad '((1 (2)) (((5 7))) 4))

