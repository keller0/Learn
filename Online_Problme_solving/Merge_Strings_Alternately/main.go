package main

import "fmt"

func main() {
	fmt.Println(mergeAlternately("abc", "pqr"))
}

func mergeAlternately(word1 string, word2 string) string {
	i := 0
	l1 := len(word1)
	l2 := len(word2)
	var result string
	for i < l1 && i < l2 {
		result += string(word1[i]) + string(word2[i])
		i++
	}
	if i < l1 {
		result += word1[i:]
	}
	if i < l2 {
		result += word2[i:]
	}
	return result
}
