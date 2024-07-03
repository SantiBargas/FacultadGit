"4. Determine el valor de las siguientes expresiones.
a. (let ((f (lambda (x) x)))
(f 'a))
b. (let ((f (lambda x x)))
(f 'a))
c. (let ((f (lambda (x . y) x)))
(f 'a))
d. (let ((f (lambda (x . y) y)))
(f 'a))"


(let ((f (lambda (x) x)))
(f 'a)) ;define un nuevo procedimiento que x = x devuelve a

(let ((f (lambda x x)))
(f 'a))  ;define un nuevo procedimiento

(let ((f (lambda (x . y) x)))
(f 'a)) ;define un nuevo procedimiento para las variables x . y devuelve x

(let ((f (lambda (x . y) y)))
(f 'a)) ;define un nuevo procedimiento para las variables x . y devuelve y