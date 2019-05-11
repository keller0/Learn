package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(def())
}

func def() string {
	defer func() {
		fmt.Println("111111111111111")
	}()
	return stop()
}

func stop() string {
	time.Sleep(2 * time.Second)
	fmt.Println("2s2s2s2s")
	defer func() {
		time.Sleep(2 * time.Second)
		fmt.Println("222222222222")
	}()
	fmt.Println("2e2e2e2e")

	return stop1()
}
func stop1() string {
	time.Sleep(2 * time.Second)
	fmt.Println("3s3s3s3s")
	defer func() {
		time.Sleep(2 * time.Second)
		fmt.Println("333333333333")
	}()
	fmt.Println("3e3e3e3e")

	return "ddd"
}
