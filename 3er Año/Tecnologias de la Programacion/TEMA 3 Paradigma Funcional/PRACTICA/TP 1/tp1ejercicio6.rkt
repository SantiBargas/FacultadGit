;6. Obtenga el elemento x de las siguientes listas:
;1. '( a b c . x)
;2. '(a b c x)
;3. '((a . x) b)
;4. '(x . a)
;5. '(a . x)

(cdr(cdr(cdr'( a b c . x))))
(car(cdr (cdr(cdr '(a b c x)))))
 (cdr(car'((a . x) b)))
 (car'(x . a))
(cdr '(a . x))