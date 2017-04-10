#lang racket
(define (5-10? x)
  (and (> x 5) (< x 10)))
;(define (>= x y)
;  (or (> x y) (= x y)))
(define (>= x y)
  (not (< x y)))