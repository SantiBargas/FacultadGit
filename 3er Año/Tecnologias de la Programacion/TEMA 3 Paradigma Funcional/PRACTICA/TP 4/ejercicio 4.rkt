;4. Cuente la cantidad de palabras y de caracteres que contiene un archivo TXT.

;Creamos el archivo txt para el ejercicio 4
;(define o (open-output-file "ejercicio4.txt"))
;(write "Este es el" o)
;(close-output-port o)

(define i (open-input-file "ejercicio4.txt"))

(define contarCaracteres
  (lambda (archivo)
   (if (eof-object? (read-char archivo))
      0
      (+ 1 (contarCaracteres archivo))
      )
    )
  )

(contarCaracteres i)
(close-input-port i)      

(define i(open-input-file "ejercicio4.txt"))
(define contarPalabras
  (lambda (archivo)
    (if (eof-object? (read archivo))
        0
        (+ 1 (contarPalabras archivo))
        )
    )
  )

(contarPalabras i)
(close-input-port i) 
   