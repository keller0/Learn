package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func maxProfit(prices []int) int {
	if len(prices) == 0 {
		return 0
	}
	var minPrice = prices[0]
	var maxProfit = 0
	for i := 1; i < len(prices); i++ {
		minPrice = min(minPrice, prices[i])
		maxProfit = max(prices[i]-minPrice, maxProfit)
	}
	return maxProfit
}

func main() {
	a := []int{}

	fmt.Println(maxProfit(a))
}
