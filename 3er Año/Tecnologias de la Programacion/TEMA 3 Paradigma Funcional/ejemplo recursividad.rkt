(define largo
 (lambda (ls)
 (if (null? ls)
 0
 (+ (largo (cdr ls)) 1)
   )
))


(largo '(a b c d))