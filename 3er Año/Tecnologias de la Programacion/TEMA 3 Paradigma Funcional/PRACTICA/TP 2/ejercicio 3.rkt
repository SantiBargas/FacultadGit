(let ((x 'a) (y 'b))
(list (let ((x 'c)) (cons x y))
(let ((y 'd)) (cons x y))))


(let ((x 'a) (y 'b))
(list (let ((z 'c)) (cons z y))
(let ((w 'd)) (cons x w))))

(let ((x '((a b) c)))
(cons (let ((x (cdr x)))
(car x))
(let ((x (car x)))
(cons (let ((x (cdr x)))
(car x))
(cons (let ((x (car x)))
x)
(cdr x))))))


(let ((x '((a b) c)))
(cons (let ((x (cdr x)))
(car x))
(let ((x (car x)))
(cons (let ((x (cdr x)))
(car x))
(cons (let ((x (car x)))
x)
(cdr x))))))

