// https://leetcode.com/problems/hand-of-straights/description/

package main

import (
	"fmt"
	"sort"
)

func main() {
	a := []int{1, 2, 3, 6, 2, 3, 4, 7, 8}

	fmt.Println(isNStraightHand(a, 3))

}

func removeEle(s []int, e int) ([]int, bool) {
	for i := 0; i < len(s); i++ {
		if s[i] == e {
			return append(s[:i], s[i+1:]...), true
		}
	}
	return s, false
}
func isNStraightHand(hand []int, W int) bool {

	if len(hand)%W != 0 {
		return false
	}
	sort.Slice(hand, func(i, j int) bool { return hand[i] < hand[j] })
	// fmt.Println(hand)
	for len(hand) > 0 {
		start := hand[0]
		// fmt.Println("for",hand)
		for i := 0; i < W; i++ {
			// fmt.Println("  for",hand)
			removed := false
			for j := 0; j < len(hand); j++ {
				// fmt.Println("    for",hand,hand[j])
				if hand[j] == start+i {
					hand = append(hand[:j], hand[j+1:]...)
					removed = true
					break
				}
			}
			if removed == false {
				return false
			}
		}
	}

	fmt.Println("hand: ", hand)
	return len(hand) == 0
}
