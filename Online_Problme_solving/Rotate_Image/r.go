package main

import "fmt"

func rotate(m [][]int)  {
	for i := 0; i < len(m); i++ {
		for j := i + 1; j < len(m); j++ {
			m[i][j], m[j][i] = m[j][i], m[i][j]
		}
	}
	for _, v := range m {
		for i, j := 0, len(v) - 1; i < j; i, j = i + 1, j - 1 {
			v[i], v[j] = v[j], v[i]
		}
	}
}
func p(m [][]int){
	for i,_ := range m{
		fmt.Println(m[i])
	}
}

func main() {
	ms := [][]int{
		{1,2,3,4},
		{5,6,7,8},
		{7,7,7,7},
		{9,9,9,9},
	}

	rotate(ms)
	p(ms)
}
