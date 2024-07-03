;;;;;;;;APLANAR Y CONCATENAR UNA LISTA;;;;;;;;;;;;;;;;;;
(define concatenar
  (lambda (list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (concatenar (cdr list1) list2))
        )))
(define APLANAR
  (lambda (ls)
    (if (null? ls)
        '()
        (if (list? (car ls))
            (concatenar (APLANAR (car ls)) (APLANAR (cdr ls)))
            (cons (car ls) (APLANAR (cdr ls)))
            ))))
;;;;;;;;;;LARGO Y QUE LISTA ES MAS CORTA;;;;;;;;;;;;;;;;;;;;;;
(define largo
 (lambda (ls)
 (if (null? ls)
      0
      (+ (largo (cdr ls)) 1))))
(define corto
  (lambda (a b)    ;a = b = lista de lista
   (if(and (list? a) (list? b))  ;preguntamos si a y b son unas listas
      (if (> (largo a) (largo b)) ;sacamos que lista es mayor
          b                         ;si a>b devolvemos b q es mas chico, si b>a o b=a devolvemos a
          a
          )
      ("NO ES UNA LISTA"))))
;;;;;;;;;;;;;DISTANCIAS ENTRE DOS PUNTOS;;;;;;;
(define distance
  (lambda (p1 p2)
    (let( (x1 (car p1)) (y1 (cdr p1)) (x2 (car p2)) (y2 (cdr p2)))
      (let ((a (- x2 x1)) (b (- y2 y1)))
        (sqrt ( + (* a a) (* b b)))))))       
;;;;;;;;;;;;;;;CUENTA ELEMENTOS DE UNA LISTA ;;;;;;;;;;;;
(define count-elem
  (lambda (x lista)
    (if (null? lista)
    0
    (if (eq? (car lista) x)
        (+ 1 (count-elem x (cdr lista)))
        (count-elem x (cdr lista))))))
;;;;;;;;;INVERSE Y FULL REVERSE;;;;;;;;;,
(define inverse
  (lambda (ls)
    (if (null? ls)
        '()
       (append(reverse (cdr ls)) (list (car ls)))
    )))
(define fullreverse
  (lambda (ls)
    (if (null? ls)
        '()
        (if (list? (car ls))
          (cons (fullreverse (cdr ls)) (list (fullreverse (car ls))))
          (concatenar(fullreverse (cdr ls)) (list (car ls)))
          ))))
;;;;;;;;;;;;;ALTURA DE UN ARBOL;;;;;;;;;;;;;;;;;;;;;;;
(define altura(lambda(l)
                (if(null? l)
                   0
                   (if(null? (cdr l))
                      1
                      (let((izq (altura (cadr l)))
                           (der (altura (caddr l))))
                        (if(> izq der)
                           (+ 1 izq)
                           (+ 1 der)))))))
;;;;;;;ELIMINAR UN ELEMENTO DE UNA LISTA;;;;;;;;;;;;;;;;;;;;
(define eliminar
  (lambda (x list)
    (if (null? list)
        '()
        (if (equal? x (car list))
            (eliminar x(cdr list))
            (cons (car list) (eliminar x (cdr list)))
            ))))
;;;;;;;AGREGAR AL FINAL UN ELEMENTO Y UNA LISTA
(define agregar-al-final
  (lambda (x lista)
    (if (null? lista)
       (list x )
        (cons (car lista) (agregar-al-final x (cdr lista))))))
(define agregar-al-final
  (lambda (lista1 lista2)
    (if (null? lista2)
        lista1 
        (cons (car lista2) (agregar-al-final lista1 (cdr lista2)))
        )))
;;;;;;;;;;;;;;;;;;;;;;ORDENAR UNA LISTA;;;;;;;;;;;;;;
(define insertar
  (lambda (e ls)
    (if (null? ls)
        (list e)
        (if (< e (car ls))
            (cons e ls)
            (cons (car ls) (insertar e (cdr ls)))
            ))))
(define ordenar_aux
  (lambda (l1 l2)
    (if (null? l1)
        l2
        (ordenar_aux (cdr l1) (insertar (car l1) l2))
        )))
;;;;;;;;;;;;;;;;;;;;MAX Y MIN DE UNA LISTA Y ORDENAR
(define elimina
  (lambda (dato lista)
    (cond
      [(null? lista) lista]
      [(eqv? dato (car lista)) (elimina dato (cdr lista))]
      [else (cons (car lista) (elimina dato (cdr lista)))]
      )))
(define minimo_elemento
  (lambda (l)
    (if (null? l)
        '()
        (if (null? (cdr l))
         (car l)
        (if (< (car l) (minimo_elemento (cdr l)))
            (car l)
            (minimo_elemento (cdr l))
            )))))
(define ordenar-lista
  (lambda (lista)
    (cond
      [(null? lista) null]
      [(cons (minimo_elemento lista) (ordenar-lista (elimina (minimo_elemento lista) lista)))]
      )))
(define maximo_elemento
  (lambda (l)
    (if (null? l)
        '()
        (if (null? (cdr l))
         (car l)
        (if (> (car l) (maximo_elemento (cdr l)))
            (car l)
            (maximo_elemento (cdr l))
            )))))
;;;;;;;;;LEER Y ESCRIBIR UN ARCHIVO;;;;;;;;;;;
(define i (open-input-file "ayuda viaje localidades.txt"))
(define j (read i))
j
(close-input-file i)

 (define o (open-output-file "saludo.txt"))
 (display "hola" o)
 (write-char #\space o)
 (display 'mundo! o)
 (newline o)
 (close-output-port o) ---> saludo.txt
                             hola mundo!
