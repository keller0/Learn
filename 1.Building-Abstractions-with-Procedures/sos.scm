#lang racket
;sos sum of square 
(define (square x)
  (* x x))
(define (sos x)
  (+ (square x) (square x)))
