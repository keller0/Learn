package main

import (
	"fmt"
	"time"
)

func counter(out chan<- int) {

	for i := 0; i < 100; i++ {
		time.Sleep(100 * time.Millisecond) //slow it down
		out <- i
	}
	close(out)

}
func square(out chan<- int, in <-chan int) {

	for x := range in {
		out <- x * x
	}
	close(out)

}

func printer(in <-chan int) {
	for x := range in {
		fmt.Println(x)
	}

}

func main() {
	naturals := make(chan int)
	squares := make(chan int)
	go counter(naturals)
	go square(squares, naturals)
	printer(squares)
}
