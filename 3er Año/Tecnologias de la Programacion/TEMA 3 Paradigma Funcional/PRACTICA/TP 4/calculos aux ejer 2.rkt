
(define dividir
  (lambda (x)
    (map (lambda (w) (/ w x)) '(10 15 20))
    )
  )

(define dividirdos
  (lambda (list x)
    (map (lambda (w) (/ w x)) list)
    )
  )

(define calculo
  (lambda (lista x)
    (map (lambda (w) (/ w x)) (lista))
    )
  )

(list 10 15 20)
(dividir 5)
(dividirdos (list 10 15 20) 5)