;8. Cree una función “app2list” que una dos elementos y los devuelve siempre como
;lista. Si los elementos son listas las junta, si es un elemento
;y una lista lo agrega y si son dos elementos crea una lista con ellos
(define agregarAlFinal
  (lambda (elem list)
    (if (null? list)
        (cons elem list)
        (cons (car list) ( agregarAlFinal elem (cdr list)) 
        )
      )
    )
  )

(define concatenar
  (lambda (list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (concatenar (cdr list1) list2))
        )
    )
  )


(define app2list
  (lambda (x y)
    (if (and (list? x) (list? y))
        (concatenar x y)
        (if (list? x)
            (agregarAlFinal y x)
            (if (list? y)
                (cons x y)
                (list x y)
                )
            )
        )
    )
  )

(app2list '(a b) '(c d))
(app2list 'a 'b)
(app2list 'a '(b c))
(app2list '(a b) 'c)

