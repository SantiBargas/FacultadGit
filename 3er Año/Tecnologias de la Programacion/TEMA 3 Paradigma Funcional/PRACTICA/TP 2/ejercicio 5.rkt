"5. Realice una función de una operación aritmética simple (+, -) y la convierta en
sintaxis de Scheme."


;tiene que recibir '(12 + 6) y convertirlo en (+ 12 6)

(define convierte_operacion (lambda (ecuacion)    ;ecuacion es mi lista
                 (let ((parametro1 (car ecuacion))
                       (operador (car (cdr ecuacion)))
                       (paramrtro2 (car (cdr (cdr ecuacion)))))
                   (cons operador(cons parametro1 (cons parametro2 '()))))))

"(define convierte_operacion (lambda (ecuacion)    ;ecuacion es mi lista
                 (let ((parametro1 (car ecuacion))
                       (operador (car (cdr ecuacion)))
                       (paramrtro2 (cdr (cdr ecuacion))))
                   (cons operador(cons parametro1 parametro2)))))"