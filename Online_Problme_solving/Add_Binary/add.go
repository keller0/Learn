package main

import (
	"fmt"
)

func addBinary(a string, b string) string {
	var ans string
	l1, l2 := len(a)-1, len(b)-1
	carry := 0
	for l1 >= 0 || l2 >= 0 {
		sum := carry
		if l2 >= 0 {
			sum += int(b[l2] - '0')
			l2--
		}
		if l1 >= 0 {
			sum += int(a[l1] - '0')
			l1--
		}
		ans = string('0'+rune(sum%2)) + ans
		carry = sum / 2
	}
	if carry != 0 {
		ans = string('0'+rune(carry)) + ans
	}
	return ans
}
func main() {
	fmt.Println(addBinary("111", "1"))
	fmt.Println(addBinary("1", "1"))
}
