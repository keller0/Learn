package main

func searchInsert(nums []int, target int) int {
	l := len(nums)
	if l == 0 {
		return 0
	}
	ans := 0
	for i, _ := range nums {
		if target <= nums[i] {
			break
		}
		ans++
	}
	return ans
}

// use binary search to do it O(log n)

func main() {
	cases := [][]int{
		{1, 2, 3, 4},
		{3, 6, 7},
		{1, 3, 5, 6},
		{},
	}
	for _, a := range cases {
		print(searchInsert(a, 7))
	}

}
