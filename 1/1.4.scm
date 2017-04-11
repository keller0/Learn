(define (a-plus-abs-b a b)
	((if (> b 0) + -) a b))
;次模型即为a加上b的绝对值
;b>0 则返回a+b
;b<0 返回a-b
