;1. Definir una estructura que represente un punto en el plano. Crear una función que
;calcule la distancia entre dos puntos datos recibiendo como parámetros la
;estructura de cada uno



(define cuadrado
 (lambda (n)
 (* n n)))

(define-struct punto (x y))


(define distance2d
  (lambda (punto1 punto2)
    (let ((X (- (punto-x punto1) (punto-x punto2))) (Y (-(punto-y punto1) (punto-y punto2))))
      (sqrt ( + (cuadrado X) (cuadrado Y)))
      )
    )
  )
  
(define punto1 (make-punto 1 1))
(define punto2 (make-punto 2 2))

(distance2d punto1 punto2)
 
