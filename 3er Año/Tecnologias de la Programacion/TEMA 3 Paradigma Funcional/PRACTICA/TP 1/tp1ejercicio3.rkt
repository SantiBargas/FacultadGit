;(car (car '((a b) (c d)))) devuelve a. Determine qué composición de car
;y cdr aplicados a ((a b) (c d)) devuelven b, c y d.
(car (car '((a b) (c d))))
(car (cdr (car '((a b) (c d)))))
(car(car (cdr '((a b) (c d)))))
(car(cdr(car (cdr '((a b) (c d))))))