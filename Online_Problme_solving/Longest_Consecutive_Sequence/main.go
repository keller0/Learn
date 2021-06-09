package main

import "fmt"

func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	numbersMap := map[int]bool{}
	for _, v := range nums {
		numbersMap[v] = true
	}
	maxC := 0
	for _, v := range nums {
		tmpMax := 1

		if _, eDown := numbersMap[v-1]; !eDown {
			for true {
				if _, eCount := numbersMap[v+1]; eCount {
					tmpMax += 1
					v++
				} else {
					break
				}
			}
		}

		maxC = max(maxC, tmpMax)
	}

	return maxC
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	fmt.Println(longestConsecutive([]int{0100, 4, 200, 1, 3, 2}))
	fmt.Println(longestConsecutive([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}))
}
