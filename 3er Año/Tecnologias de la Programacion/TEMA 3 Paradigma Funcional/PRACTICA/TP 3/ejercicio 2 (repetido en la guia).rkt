;Defina un procedimiento subst que reciba tres parámetros (dos valores y una lista) y 
;devuelva la lista con todos los componentes que son iguales al primer parámetro 
;reemplazados por el valor del segundo parámetro.
;(subst 'c 'k '( c o c o n u t)) → (k o k o n u t)

(define subst
  (lambda(x y list)
    (if(null? list)
    '()
    (if (eqv? (car list) x)
        (cons y (subst x y (cdr list)))
        (cons (car list) (subst x y (cdr list)))
        )
    )
    )
  );cierro define
  