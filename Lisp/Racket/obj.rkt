#lang slideshow
(require pict/flash)
(require slideshow/code)

(define-syntax pict+code
  (syntax-rules ()
    [(pict+code expr)
     (hc-append 10
                expr
                (code expr))]))
(require racket/class
         racket/gui/base)
(define f (new frame% [label "Chuib"]
                      [width 300]
                      [height 300]
                      [alignment '(center center)]))

;(send f show #t)

(define (add-drawing p)
  (let ([drawer (make-pict-drawer p)])
    (new canvas% [parent f]
                 [style '(border)]
                 [paint-callback (lambda (self dc)
                                   (drawer dc 0 0))])))


;(add-drawing (pict+code (circle 10)))

;(add-drawing (colorize (filled-flash 50 30) "yellow"))
 
