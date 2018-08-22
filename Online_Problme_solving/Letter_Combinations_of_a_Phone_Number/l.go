package main

import (
	"fmt"
)

func letterCombinations(digits string) []string {
	board := map[int]string{
		2: "abc", 3: "def",
		4: "ghi", 5: "jkl", 6: "mno",
		7: "pqrs", 8: "tuv", 9: "wxyz",
	}
	if len(digits) == 0 {
		return []string{}
	}
	ans := []string{""}
	for i := range digits {
		tans := []string{}
		num := int(digits[i] - '0')
		if num < 2 || num > 9 {
			break
		}
		c, e := board[num]
		if !e {
			continue
		}
		for _, s := range ans {
			for _, ss := range c {
				tans = append(tans, s+string(ss))
			}
		}
		ans = tans
	}

	return ans
}
func main() {
	fmt.Println(letterCombinations("233"))
}
