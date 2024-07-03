(define factorial
  (lambda (x)
    (if (zero? x)
        1
        ( * (factorial (- x 1)) x))
    )
  )

(factorial 5)

