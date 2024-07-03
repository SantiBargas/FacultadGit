"Determine el valor de la siguiente expresión. Explique como ha derivado este valor."
(let ((x 9))
(* x
(let ((x (/ x 3)))
(+ x x))))

;Primero declara que x=9
;despues multiplica x * (let ((x (/ x 3)))(+ x x))
;let ((x (/ x 3))) esto hace que x = x/3
; por ultimo suma las x entonces es:
; 9*3 = 27 y x+x = 27 + 27 = 54

