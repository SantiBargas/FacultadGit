;3. Calcule la distancia máxima entre dos puntos de una lista, usando el predicado
;MAP y estructuras.

(define cuadrado
 (lambda (n)
 (* n n)))

(define-struct punto2d (x y))


(define distance2d
  (lambda (punto1 punto2)
    (let ((X (- (punto-x punto1) (punto-x punto2))) (Y (-(punto-y punto1) (punto-y punto2))))
      (sqrt ( + (cuadrado X) (cuadrado Y)))
      )
    )
  )

"con un let nos guardamos el primer punto, en cada proceso recursivo nos guardamos
el primer punto
agarramos el punto y calculamos la distancia 2d con cada punto
despues armamos una lista con las distancias de cada punto"



(define punto1 (make-punto2d 1 1))
(define punto2 (make-punto2d 2 2))
(define punto3 (make-punto2d 3 3))
(define punto4 (make-punto2d 4 4))
(define punto5 (make-punto2d 10 20))
(define listap (list punto1 punto2 punto5 punto4 punto3))

;crea una lista con las distancias de cada punto con cada punto
(define distancias
  (lambda (ls)
    (if (null? ls)
        '()
        (let ((p (car ls)))
          (map cons ((lambda(cdr ls) (dist2d p (cdr ls)))) (distancias (cdr ls)))
          )
        )
    )
  )

;crea una lista con las distancias entre todos los puntos
(define distancias2
  (lambda (ls)
    (if (null? ls)
        '()
        (let ((p (car ls)))
          (map cons ((lambda(cdr ls) (dist2d p (cdr ls)))) (distancias (cdr ls)))
          )
        )
    )
  )

(distancias '((1 . 1) (1 . 2) (1 . 3) (1 . 4)))
                                                                   ;el argumento seria cada uno de los puntos que le siguen a p
                                                                    ;seria la lista de puntos argumentos
                                                                    ;tenemos que seguir operando con la llamada recursiva
 ; si no queremos usar el let usamos (dist2d p arg) = (dist2d (car list) arg)
 ;equivalente a concatenar el append