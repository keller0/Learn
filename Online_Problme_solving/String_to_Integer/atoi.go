package main

import (
	"fmt"
)

func main() {
	cases := []string{
		"",
		" ",
		" -",
		"42",
		"123",
		"-123",
		"   123",
		"   -123",
		"123 word",
		"word 123",
		"13123123124123213",
		"-12333333333222222",
	}
	for _, s := range cases {
		fmt.Println(s, myAtoi(s))
	}
}

func myAtoi(str string) int {

	var sing, i = 1, 0
	for i < len(str) && str[i] == ' ' {
		i++
	}
	if len(str[i:]) == 0 {
		return 0
	}
	if str[i] == '+' {
		i++
	} else if str[i] == '-' {
		sing = -1
		i++
	}
	var ans int
	for i < len(str) && str[i] >= '0' && str[i] <= '9' {
		if (ans > 2147483647/10) || (ans == 2147483647/10 && str[i]-'0' > 7) {
			if sing == -1 {
				return -2147483648
			}
			return 2147483647
		}
		ans = 10*ans + int(str[i]-'0')
		i++
	}
	return ans * sing
}
