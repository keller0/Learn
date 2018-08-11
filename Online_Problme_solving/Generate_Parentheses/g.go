package main

import "fmt"

func generateParenthesis(n int) []string {
	return makePar("", n, n)
}

func makePar(p string, l, r int) []string{
	if l < 0 || r < 0 {
		return nil
	}
	if l ==0 && r ==0 {
		return []string{p}
	}
	if l > r {
		return nil
	}
	if l == r {
		return makePar(p+"(", l-1, r)
	}

	return append(makePar(p+"(", l-1, r), makePar(p+")", l, r-1)...)
}
func main() {


	ps := generateParenthesis(3)
	for _, arr := range ps {
		fmt.Println(arr)
	}

}
