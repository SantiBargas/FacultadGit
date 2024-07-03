;1. Reescriba las siguientes expresiones, usando Let para remover las subexpresiones
;comunes y para mejorar la estructura del código. No realice ninguna simplificación
;algebraica.
;a. (+ (/ (* 7 a) b) (/ (* 3 a) b) (/ (* 7 a) b))
;b. (cons (car (list a b c)) (cdr (list a b c)))


(define a 10)
(define b 20)
(define c 30)

(let ((x (* 7 a)) (y (* 3  a))); x es 7*a , y es 3*a
  (+ (/ x b) (/ y b) (/ x b )))


(let ((x '(a b c)))
  (cons (car( list x ))(cdr( list x ))))



;(let ((x (* 7 a)) (y (* 3  a))); x es 7*a , y es 3*a
 ; (let ((w ( / x b)) (z y))
  ;      ((+ w (/z b) w))))"


