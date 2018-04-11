package main

import (
	"fmt"
	"time"
)

func main() {
	naturals := make(chan int)
	squares := make(chan int)

	go func() {
		for i := 0; i < 100; i++ {
			time.Sleep(100 * time.Millisecond) //slow it down
			naturals <- i
		}
		close(naturals)
	}()
	//Square
	go func() {
		for x := range naturals {
			squares <- x * x * x
		}
		close(squares)
	}()

	for x := range squares {
		fmt.Println(x)
	}
}
