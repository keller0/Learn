// ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/description/

package main

import (
	"fmt"
)

func main() {
	test := []string{"abcdefg", "1234567"}
	for _, t := range test {
		fmt.Println(t, ":", convert(t, 2))
	}
}

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	l := len(s)
	var rowNum int
	if l < numRows {
		rowNum = l
	} else {
		rowNum = numRows
	}
	currentRow := 0
	down := false
	ss := make([]string, rowNum)

	for i := 0; i < l; i++ {

		if currentRow == 0 || currentRow == rowNum-1 {
			down = !down
		}
		ss[currentRow] += string(s[i])
		if down {
			currentRow++
		} else {
			currentRow--
		}
	}

	var ans string
	for i := 0; i < len(ss); i++ {
		ans += ss[i]
	}
	return ans
}
