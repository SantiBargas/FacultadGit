;9. Definir la función calcula-cuadrados que recibe una lista de números y devuelve
;otra lista con el cuadrado de cada elemento.
;(calcula-cuadrados ’(1 2 3 4)) → (1 4 9 16)

(define cuadrado
 (lambda (x)
   (* x x)
   )
 )

(define calcula-cuadrados
  (lambda (lista)
    (map (lambda (x) (cuadrado x )) lista)
    )
  )

(calcula-cuadrados '(1 2 3 4))