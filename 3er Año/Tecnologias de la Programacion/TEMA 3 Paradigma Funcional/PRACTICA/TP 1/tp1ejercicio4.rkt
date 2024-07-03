;4. El comportamiento de (car (car (car '((a b c) (d))))) no está definido porque
;(car '((a b c) (d))) es (a b c),
;(car '(a b c)) es a, y
;(car 'a) no está definido.
;Determine todas las combinaciones legales de car y cdr aplicables a ((a b) (c d)).

 (car '((a b) (c d)))
(car(car '((a b) (c d))))
 (cdr(car '((a b) (c d))))
 (car(cdr '((a b) (c d))))
(cdr(cdr '((a b) (c d))))
(cdr(car (cdr'((a b) (c d)))))