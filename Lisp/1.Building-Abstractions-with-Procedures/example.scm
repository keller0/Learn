#lang racket
(define (SUM TERM A NEXT B)
  (if (> A B)
      0
      (+ (TERM A)
         (SUM TERM (NEXT A)
              NEXT
              B))))
(define (inc1 x)
  (+ x 1))