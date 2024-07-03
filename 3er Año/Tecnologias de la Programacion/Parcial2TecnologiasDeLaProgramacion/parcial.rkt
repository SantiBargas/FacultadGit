
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


(define contar-calorias ;;FUNCION QUE cuenta las calorias con el reemplazo incluido
  (lambda (lista)
    (if (null? lista)
        0
        (+ (cdr(car lista)) (contar-calorias (cdr lista)))
    )
  )
 )
;(contar-calorias'(("DESAYUNO" . 120)("ALMUERZO" . 280)("MERIENDA" . 110)("CENA" . 220)("ALMUERZO" . 380)))

(define contarPorDia  ;FUNCION QUE CUENTA LAS CALORIAS PASANDOLE UN DIA POR REFERENCIA
  (lambda (dia lista)
    (if (null? lista)
        0
    (if (equal? dia (car(car lista)))
        (contar-calorias (APLANAR (cdr (car comidas))))
        (contarPorDia dia (cdr comidas))
        )
      )
    )
  )
;(contarPorDia "Lunes" comidas)

(define checkSupero      ;FUNCION QUE CONTROLA SI EL DIA SUPERO O NO LAS CALORIAS CON EL REEMPLAZO
  (lambda (limite lista)
    (let ( (a (car lista)))
     (let ( (b (contar-calorias (APLANAR(cdr lista)))))
       (if (> b limite)
           #t
           #f
           )
       )
      )
    )
  )
;(checkSupero 1200 '("Lunes" (("DESAYUNO" . 120) ("ALMUERZO" . 280) ("MERIENDA" . 110) ("CENA" . 220)) (("ALMUERZO" . 380))))

;(define concatenar  ;funcion que concatena "Lunes" con (("DESAYUNO" . 120) ("ALMUERZO" . 280) ("MERIENDA" . 110) ("CENA" . 220))
 ; (lambda (dia menu)


(define correcto
  (lambda (limite lista)
    (if (null? lista)
        '()
       (let ( (a (car lista)) (b (car (cdr (car lista)))))
         (if (checkSupero limite (car lista))
             (cons (car(cdr (car lista))) (correcto limite (cdr lista)))  ;si lo supero tengo que eliminar de la lista la ultima lista  con el reemplazo
             (cons (car lista) (correcto limite (cdr lista)))     ;si no supero agrego el dia entero a la lista
             )
         )
       )
    )
  )
;(correcto 800 '( ("Lunes" (("DESAYUNO" . 120)("ALMUERZO" . 280)("MERIENDA" . 110)("CENA" . 220)) (("ALMUERZO" . 380)) )))

;;;Me falto concatenar el dia con el menu correctamente

(correcto 800 '( ("Lunes" (("DESAYUNO" . 120)("ALMUERZO" . 280)("MERIENDA" . 110)("CENA" . 220)) (("ALMUERZO" . 380)) )
  ("Martes" (("DESAYUNO" . 120)("ALMUERZO" . 295)("MERIENDA" . 90)("CENA" . 250)) (("ALMUERZO" . 295)) )
  ("Miércoles" (("DESAYUNO" . 125)("ALMUERZO" . 270)("MERIENDA" . 95)("CENA" . 290)) (("CENA" . 220)) )
  ("Jueves" (("DESAYUNO" . 130)("ALMUERZO" . 270)("MERIENDA" . 120)("CENA" . 280)) (("MERIENDA" . 70)) )
  ("Viernes" (("DESAYUNO" . 120)("ALMUERZO" . 275)("MERIENDA" . 115)("CENA" . 270)) () )
))

