package main

import "fmt"

func minCostClimbingStairs(cost []int) int {
	a, b := cost[0], cost[1]
	l := len(cost)
	for i := 2; i < l; i++ {
		a, b = b, min(a, b)+cost[i]
	}
	return min(a, b)
}

func min(a, b int) int {

	if a >= b {
		return b
	}
	return a
}

func main() {
	fmt.Println(minCostClimbingStairs([]int{10, 15, 20}))
	fmt.Println(minCostClimbingStairs([]int{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}))
}
