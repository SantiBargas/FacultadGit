;12.Definir una función que permita obtener la altura de un árbol que está
;representadado por listas anidadas donde cada lista contiene los nodos
;correspondientes a su nivel. Ej: ( ( (1 2) (3 4 5) ) 6 (7 (8 (9 (10 11))))) representaría:

(define altura
  (lambda (lista)
    (if (null? lista)
        0
        (if (not(list? (car lista))) ; Si no es una lista el car
            (if(not(null? (cdr lista)))
               (altura (cdr lista))
               0
               )
           (let((pri_elem (+ 1 (altura (car lista))))
                (resto (altura (cdr lista))))  ;Si el car es una lista
                  (if (> pri_elem resto)
                      pri_elem
                      resto
                      )
                  )
              )
            )
        )
    )

(altura '( ( (1 2) (3 4 5) ) 6 (7 (8 (9 (10 11))))))