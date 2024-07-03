;4. Definir una función que añada un elemento a una lista en caso de que aquel no se
;encuentre en ésta.
;(addif 'a '(b c d)) → '(b c d a)
;(addif 'a '(a b c d)) → '(a b c d)
;(addif 'c '(b c d)) → '(b c d)

(define agregarAlFinal
  (lambda (elem list)
    (if (null? list)
        (cons elem list)
        (cons (car list) ( agregarAlFinal elem (cdr list)) 
        )
      )
    )
  )
          
(define perteneceAux
  (lambda (atomo list1)
    (if (null? list1)
        #f
        (if (equal? atomo (car list1))
            #t
            (perteneceAux atomo (cdr list1))
            )
        )
    )
  )

(define addif
  (lambda (atomo list)
    (if (perteneceAux atomo list)
        list
        (agregarAlFinal atomo list)
        )
    )
  )
            
(addif 'a '(b c d))
(addif 'a '(a b c d))
(addif 'c '(b c d))