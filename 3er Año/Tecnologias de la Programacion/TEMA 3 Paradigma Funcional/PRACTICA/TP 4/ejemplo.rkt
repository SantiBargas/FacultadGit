(define i (open-input-file "ejemplo.txt"))
(read-char i)
(read-line i)

;(define o (open-output-file "ejemplo3.txt"))
;(write-char #\h o)
;(write-char #\o o)
;(write-char #\l o)
;(write-char #\a o)
;(close-output-port o)

(map length '((1 2 3) (a s d)))
(map list? '((1 2 3) (a s d)))

;mirar como nos simplifica map
(define cuadrado  ;funcion engorrosa
  (lambda (list)
    (if (null? list)
        '()
        (cons (expt (car list) 2) (cuadrado (cdr list)))
        )
    )
  )

(map (lambda(e)(expt e 2)) '(1 2 3))