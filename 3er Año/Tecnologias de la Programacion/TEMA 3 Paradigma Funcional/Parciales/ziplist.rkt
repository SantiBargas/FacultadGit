;Cree una función zipList que reciba como parámetro una lista propia y devuelva como resultado una lista con los elementos ordenados de a pares impropios indicando en el primer elemento del par el objeto y en el segundo la cantidad de elementos iguales que se encuentran en forma consecutiva. 

;Ej:
;(zipList '(a a a b a b b c c)) --> ((a . 3) (b . 1) (a . 1) (b . 2) (c . 2))

(define count-elem  ;cuenta los elementos repetidos seguidos
  (lambda (x lista)
    (if (null? lista)
    0
    (if (eq? (car lista) x)
        (+ 1 (count-elem x (cdr lista)))
        0))))

(count-elem 'a '(a a a b a b b c c))

(define eliminar-seguidos
  (lambda (x lista)
    (if (null? lista)
        '()
        (if (equal? (car lista) x)
            (eliminar-seguidos x (cdr lista))
            lista))))
(eliminar-seguidos 'a '(a a a b a b b c c))

(define crearListaAux
  (lambda (lista)
    (cons (car lista) (count-elem (car lista) lista))
    )
  )
(crearListaAux '(a a a b a b b c c))

(define zipList
  (lambda (lista)
    (if (null? lista)
        '()
        (cons (crearListaAux lista) (zipList (eliminar-seguidos (car lista) lista)))
        )
    )
  )
(zipList '(a a a b a b b c c))