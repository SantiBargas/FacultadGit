;5. Cree una función que permita mostrar por pantalla un archivo de texto.

;Creamos el archivo txt para el ejercicio 5
;(define o (open-output-file "ejercicio5.txt"))
;(write "Este es el ejercicio 5" o)
;(close-output-port o)


(define leerTexto
  (lambda (i)
    (define linea (read-line i))
    (if (eof-object? linea)
        (display "\n")
        (and (display linea) (leerTexto i))
        )
    )
  )

(define i (open-input-file "ejercicio5.txt"))
(leerTexto i)
(close-input-port i)
