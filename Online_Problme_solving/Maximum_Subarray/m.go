package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	sum, maxSum := nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		sum = max(nums[i], sum+nums[i])
		maxSum = max(maxSum, sum)
	}
	return maxSum
}

func main() {
	a := []int{-1, 0, 2, -1}

	fmt.Println(maxSubArray(a))
}
