;Describa los pasos necesarios para evaluar la siguiente expresión:
;((car (cdr (cdr (list + - * /)))) 5 5)

"Se crea una lista con los operadores + - * / "
"Se obtiene con cdr los elementos - * / "
"Se obtiene con cdr los elementos * / "
" Se obtiene con car el primer elemento que es * "
"Se realiza la multiplicacion (5*5) -> * 5 5 "

((car (cdr (cdr (list + - * /)))) 5 5)