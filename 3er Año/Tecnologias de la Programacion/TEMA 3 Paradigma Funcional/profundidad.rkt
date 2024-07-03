
(define profundidad
  (lambda(ls)
    (if (null? ls)
        0 ;lista vacia 
        (if (null? (cdr ls))
            1
            (let ((izq (profundidad(cadr (ls)))
                  (der (profundidad (caddr ls))))
                  (if(> izq der)
                     (+ 1 izq)
                     (+ 1 der))
            )
        )
    )
  )
 )
)  