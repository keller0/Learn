package main

import (
	"fmt"
)

func strStr(haystack string, needle string) int {
	if len(needle) == 0 {
		return 0
	}
	l := len(haystack)
	if l < len(needle) {
		return -1
	}
	for i, _ := range haystack {
		if haystack[i] == needle[0] {
			for j, _ := range needle {
				if i+j >= l || haystack[i+j] != needle[j] {
					break
				}
				if j == len(needle)-1 {
					return i
				}
				continue
			}
		}
	}
	return -1
}

func strStr2(haystack string, needle string) int {
	if len(needle) == 0 {
		return 0
	}

	result := -1
	l := len(haystack)
	l2 := len(needle)
	for i := 0; i < l; i++ {
		if l < i+l2 {
			return -1
		}
		if haystack[i:i+l2] == needle {
			return i
		}
	}
	return result
}

func main() {
	cases := map[string]string{
		"asd":   "asd",
		"a":     "asd",
		"":      "asd",
		"as":    "",
		"ppppp": "asp",
	}
	for a, b := range cases {
		fmt.Println(a, b)
		fmt.Println(strStr(a, b), strStr2(a, b))
	}

}
