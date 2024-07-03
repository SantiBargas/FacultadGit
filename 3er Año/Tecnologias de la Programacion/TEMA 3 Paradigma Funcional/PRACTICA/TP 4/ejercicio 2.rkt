;2. Definir una estructura que represente un punto en el espacio. Crear una función
;que calcule el centro de gravedad de una lista de puntos en el espacio
;representados por la estructura definida previamente.

(define-struct punto (x y z))
(define a (make-punto 1 2 3))
(define b (make-punto 1 2 3))
(define c (make-punto 1 2 3))
(list a b c)

;Para calcular el centro de gravedad sumas todas las x, todas las y, todas las z
;y dividimos por la cantidad de puntos

;Funcion sumatoria
(define sumatoria
  (lambda(lista)
    (if (null? lista)
        '(0 0 0)
        (let ((e (car lista)))
          (map + (list (punto-x e) (punto-y e) (punto-z e)) (sumatoria (cdr lista)))
      )
    )
  ))
(sumatoria (list a b c))
;Funcion calculo
(define calculo
  (lambda (list x)
    (map (lambda (w) (/ w x)) list)
    )
  )
;no me anduvo esta

;Funcion wrapper
(define gravedad
  (lambda(lista)
    (let
        ((suma (sumatoria lista)) (largo (length lista)))
      (map (lambda(e) (/ e largo)) suma)
      )
    )
  )

(gravedad (list a b c))
    