// -*- mode:go;mode:go-playground -*-
// snippet of code @ 2018-06-10 02:46:39

// === Go Playground ===
// Execute the snippet with Ctl-Return
// Remove the snippet completely with its dir and all files M-x `go-playground-rm`

// Problem from leetcode
// https://leetcode.com/problems/shifting-letters/description/
package main

import (
	"fmt"
)

func main() {
	s := "abc"
	shift := []int{3,51,1}			
	a := shiftingLetters(s, shift)

	fmt.Println("Results:",a)

}

func shiftingLetters(S string, shifts []int) string {
	var X = 0
	for _, shift := range shifts{
		X += shift % 26
	}
	fmt.Println(X)
	var ans string
	for i:=0; i < len(S); i++ {
		var index rune
		index = rune(S[i]) -'a'
		fmt.Println(index, X)
		ans += string(rune((int(index)+X)%26) + 'a')
		X = X-shifts[i]%26
	}
	
	return ans
}
