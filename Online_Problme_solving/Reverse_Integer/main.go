package main

import (
	"fmt"
	"math"
)

func reverse(x int) int {
	var result int
	var belowZero bool
	if x < 0 {
		belowZero = true
	}
	for x != 0 {
		result = result*10 + x%10
		x = x / 10
		if result > math.MaxInt32 || result < math.MinInt32 {
			return 0
		}
		if (belowZero && result > 0) || (!belowZero && result < 0) {
			return 0
		}
	}
	return result
}

var testCases = []struct {
	input  int
	output int
}{
	{123, 321},
	{-123, -321},
	{120, 21},
	{0, 0},
	{2147483647, 0},
	{2147483646, 0},
	{-2147483648, 0},
	{-2147483646, 0},
}

func main() {

	// -2147483648 --> 2147483647

	for _, c := range testCases {
		i := c.input
		o := c.output
		n := reverse(i)
		fmt.Println(i, n)

		if o != n {
			fmt.Println("Test case failed")
		}
	}

}
