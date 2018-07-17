package main

import "fmt"

func twoSum(a []int, target int) []int {
	m := make(map[int]int)
	for i, v := range a {
		complement := target - v
		if j, ok := m[complement]; ok {
			return []int{j, i}
		}
		m[v] = i
	}
	return []int{}
}
func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8}
	t := 9
	fmt.Println(twoSum(array, t))
}
