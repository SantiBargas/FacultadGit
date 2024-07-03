;6. Defina en Racket un procedimiento recursivo que encuentre
;el primer elemento de una lista que es un número.
;Debe retornar el número si lo encuentra, sino retornar null.
;Ej: (primer-num '((1 . 2) 'a (b) (5) 6 8 'a 9) → 6


(define primer-num
  (lambda (list)
         (if (null? list)
         null
         (if (number? (car list))
             (car list)
             (primer-num (cdr list))
             )
         )
    )
  )

    
(primer-num '((1 . 2) 'a (b) (5) 6 8 'a 9))