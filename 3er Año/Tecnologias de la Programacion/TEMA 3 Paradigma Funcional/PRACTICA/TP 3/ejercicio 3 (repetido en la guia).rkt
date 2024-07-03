;Se desea crear un función que reciba como parámetros una lísta de átomos compuesto 
;únicamente de letras y devuelva una lista agrupando los que son iguales en sublistas. 
;Ej: (agrupar '(A A B C A B A D C)) --> ((AAAA) (BB) (CC) (D))

;Este procedimiento elimina los elementos repetidos de una lista
(define eliminar
  (lambda (x list)
    (if (null? list)
        '()
        (if (equal? x (car list))
            (eliminar x(cdr list))
            (cons (car list) (eliminar x (cdr list)))
            )
        )
    )
  )

;Esta funcion construye una lista con los elementos repetidos
(define iguales
  (lambda(x list)
    (if(null? list)
    '()
    (if (equal? x (car list) )
        (cons x (iguales x (cdr list)))
        (iguales x (cdr list)))
        )
    )
   )

(define agrupar
  (lambda (list)
    (if (null? list)
        '()
        (cons (iguales (car list) list) (agrupar (eliminar (car list) list)))
        )
    )
  )

(eliminar 'A '(A A B C A B A D C))
(agrupar '(A A B C A B A D C))
(iguales 'A '(A A B C A B A D C))