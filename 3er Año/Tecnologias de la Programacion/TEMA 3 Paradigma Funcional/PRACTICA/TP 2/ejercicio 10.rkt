;.Defina una función distance2d que reciba como parámetros dos puntos en el
;plano y devuelva su distancia. Utilice una lista impropia para la declaración de x e y.
;Ej: (distance2d '(1 . 1) '(2 . 2)) → 1.41

(define cuadrado
 (lambda (n)
 (* n n)))

(define distance2d
 (lambda (x1 y1 x2 y2)
   (let ((a (- x2 x1)) (b (- y2 y1)))
     (sqrt ( + (cuadrado a) (cuadrado b)))
     )
   )
 )

 
(define distance
  (lambda (p1 p2)
    (let( (x1 (car p1)) (y1 (cdr p1)) (x2 (car p2)) (y2 (cdr p2)))
      (let ((a (- x2 x1)) (b (- y2 y1)))
        (sqrt ( + (cuadrado a) (cuadrado b)))
        )
      )
    )
  )
        
                          
 (distance '(1 . 1) '(2 . 2))