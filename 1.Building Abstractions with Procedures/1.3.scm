#lang racket
(define 2of3 (lambda (x y z)
              (cond ((and (< x y)  (< x z)) (+ y z))
                    ((and (< y x)  (< y z)) (+ x z))
                    (else (+ x y)))))
      