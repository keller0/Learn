package main

import (
	"fmt"
)

func main() {
	fmt.Println(plusOne([]int{1, 2, 3}))
	fmt.Println(plusOne([]int{0}))
	fmt.Println(plusOne([]int{9}))
	fmt.Println(plusOne([]int{9, 9}))
}

func plusOne(digits []int) []int {
	index := len(digits) - 1
	carry := 1
	var ans = make([]int, 0, len(digits)+1)

	for ; index >= 0; index-- {
		if carry == 1 {
			if digits[index] == 9 {
				ans = append([]int{0}, ans...)
				carry = 1
			} else {
				ans = append([]int{digits[index] + 1}, ans...)
				carry = 0
			}
		} else {
			ans = append([]int{digits[index]}, ans...)
		}
	}
	if carry == 1 {
		ans = append([]int{1}, ans...)
	}
	return ans
}
