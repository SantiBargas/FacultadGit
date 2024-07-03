;6. Ordenar por Peso ASCII
;Se desea crear una función que reciba como parámetro una lista de strings y
;devuelva una lista con las cadenas ordenadas por su peso ASCII. Ej:
;> (ordenar '("moto" "auto" "casa" "juego" "aire")) --> ("casa" "aire" "auto" "moto"
;"juego")
;El peso ascii de una palabra se calculará como la suma de los valores de cada uno
;de los caracteres que la componen. Ejemplo:
;(pesopalabra "casa") --> 408
;a = 97
;c = 99
;s = 115 ==> 99 + 97 + 115 + 97 = 408


;(map char->integer (string->list "Hola"))
;(cons +(map char->integer(string->list "Hola")))
;(eval (cons + (map char->integer (string->list "Hola"))))
;(eval (cons length '((list 1 2 3))))


;;hacer una funcion que sume todos los elementos de una lista

(define sumarlist
  (lambda (list)
    (if (null? list)
        0
        (+ (car list) (sumarlist(cdr list))   )
        )
    )
  )
(sumarlist(map char->integer (string->list "moto")))

;pesopalabra con lista
(define pesoRecursivo
  (lambda(ls)
    (if (null? ls)
        '()
    (cons(sumarlist(map char->integer (string->list (car ls)))) (pesoRecursivo (cdr ls)))
         )
      )
  )
(pesoRecursivo '("moto" "auto" "casa" "juego" "aire"))

;construimos la lista con el string y su peso
;Wrapper
(define listaPalabra
  (lambda (ls)
    (map cons ls (pesoRecursivo ls))
    )
)
(listaPalabra '("moto" "auto" "casa" "juego" "aire"))

;Funcion para insertar un elemento en una lista ordenada
(define insertar
  (lambda (e ls)
    (if (null? ls)
        (list e)
        (if (< (cdr e) (cdar ls))
            (cons e ls)
            (cons (car ls) (insertar e (cdr ls)))
            )
        )
    ))
(insertar '("moto" . 447) '(("casa" . 408) ("auto" . 441) ("juego" . 538)))

(define ordenar_aux
  (lambda (l1 l2)
    (if (null? l1)
        l2
        (ordenar_aux (cdr l1) (insertar (car l1) l2))
        )
    ))

; Funcion para obtener las palabras de la lista impropia
(define palabras
  (lambda (ls)
    (if (null? ls)
        '()
        (cons (caar ls) (palabras (cdr ls))))))

; Funcion Principal
(define ordenar
  (lambda (ls)
    (if (null? ls)
        '()
        (palabras (ordenar_aux (listaPalabra ls) '())))))

(ordenar '("moto" "auto" "casa" "juego" "aire"))