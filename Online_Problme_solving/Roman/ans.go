package main

import (
	"fmt"
	"strings"
)

func intToRoman(num int) string {
	var ans = ""
	ans += strings.Repeat("M", num/1000)
	num %= 1000

	h := num / 100
	num %= 100
	if h < 4 {
		ans += strings.Repeat("C", h)
	} else if h == 4 {
		ans += "CD"
	} else if h == 5 {
		ans += "D"
	} else if h == 9 {
		ans += "CM"
	} else if h > 5 {
		ans += "D"
		ans += strings.Repeat("C", h-5)
	}

	var t = num / 10
	num %= 10
	if t < 4 {
		ans += strings.Repeat("X", t)
	} else if t == 4 {
		ans += "XL"
	} else if t == 5 {
		ans += "L"
	} else if t == 9 {
		ans += "XC"
	} else if t > 5 {
		ans += "L"
		ans += strings.Repeat("X", t-5)
	}

	if num < 4 {
		ans += strings.Repeat("I", num)
	} else if num == 4 {
		ans += "IV"
	} else if num == 5 {
		ans += "V"
	} else if num == 9 {
		ans += "IX"
	} else if num > 5 {
		ans += "V"
		ans += strings.Repeat("I", num-5)
	}

	return ans
}

var charMap = map[string]int{
	"I": 1, "V": 5,
	"X": 10, "L": 50,
	"C": 100, "D": 500,
	"M": 1000,
}

func romanToInt(s string) int {
	ans, t := 0, 0
	for i := 0; i < len(s); i++ {
		num := charMap[string(s[i])]
		if num > t {
			ans += num
			ans -= t * 2
		} else {
			ans += num
		}
		t = num
	}
	return ans
}

func main() {

	cases := []int{0, 1, 2, 3, 4, 9, 10, 14, 400, 3999}

	for _, t := range cases {
		r := intToRoman(t)
		fmt.Println(t, r, romanToInt(r))
	}
}
