package main

import (
	"fmt"
	"time"
)

func ack(m, n int) int {
	if m == 0 {
		return n + 1
	} else if m > 0 && n == 0 {
		return ack(m-1, 1)
	} else if m > 0 && n > 0 {
		return ack(m-1, ack(m, n-1))
	}
	return 0
}

func main() {

	for i := 0; i < 100; i++ {
		for j := 0; j <= i; j++ {
			start := time.Now()
			a := ack(i, j)
			fmt.Printf("ack(%d,%d)=%d %d nanoseconds\n", i, j, a, time.Now().Sub(start).Nanoseconds())
		}
	}
}
