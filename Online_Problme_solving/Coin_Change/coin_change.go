package main

import (
	"fmt"
)

func main() {
	var a int
	a = 10
	changes := [3]int{1, 2, 3}
	ways := make([]int, a+1)
	ways[0] = 1
	for _, c := range changes {
		for j := c; j <= a; j++ {
			ways[j] += ways[(j - c)]
		}
	}
	fmt.Println(ways[a])
}
