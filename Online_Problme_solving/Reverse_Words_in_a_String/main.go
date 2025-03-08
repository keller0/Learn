package main

import (
	"fmt"
	"strings"
)

func main() {
	test := "the sky is blue"
	fmt.Println("\"" + reverseWords(test) + "\"")

}
func reverseWords(s string) string {

	words := strings.Fields(s)
	l := len(words)
	for i := 0; i < l/2; i++ {
		// fmt.Println(i, l-i)
		words[i], words[l-1-i] = words[l-1-i], words[i]
	}

	return strings.Join(words, " ")

}

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
// O(1) extra space way
// todo: implement this
