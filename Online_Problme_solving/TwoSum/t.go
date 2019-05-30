package main

import "fmt"

var p = fmt.Println

func twoSum(a []int, target int) []int {
	i1, i2 := 0, len(a)-1
	for i1 < i2 {
		if a[i1]+a[i2] < target {
			i1++
		} else if a[i1]+a[i2] > target {
			i2--
		} else {
			return []int{i1 + 1, i2 + 1}
		}
	}
	return []int{}
}
func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8}
	t := 9
	p(twoSum(array, t))
}
