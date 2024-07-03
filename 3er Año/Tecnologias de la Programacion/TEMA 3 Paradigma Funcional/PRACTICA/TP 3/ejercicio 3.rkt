;Escriba una función que cuente la cantidad de apariciones de un elemento en una lista. 
;El primer parámetro será el elemento a buscar y el segundo la lista en la que se deber 
;buscar. 
;(count-elem 3 '(1 2 3 4 5 4 3 2 1 )) 2

(define count-elem
  (lambda (x lista)
    (if (null? lista)
    0
    (if (eq? (car lista) x)
        (+ 1 (count-elem x (cdr lista)))
        (count-elem x (cdr lista))
        ) ;cierro if
    );cierro 2if
    );cierro lambda
  )

(count-elem 5 '(1 2 3 4 5 4 3 2 1 ))