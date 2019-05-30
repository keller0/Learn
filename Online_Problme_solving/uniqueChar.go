package main

import (
	"fmt"
)

func main() {
	s := "abcdefabcde"
	var a int32
	for _, c := range s {
		a ^= c
	}

	fmt.Println(string(a))
}
