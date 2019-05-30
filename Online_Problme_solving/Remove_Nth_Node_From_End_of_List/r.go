package main

import "fmt"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	n1, n2 := head, head
	for n1 != nil && n1.Next != nil && n > 0 {
		n1 = n1.Next
		n--
	}
	for n1 != nil && n1.Next != nil {
		n2 = n2.Next
		n1 = n1.Next
	}
	if n2 != nil && n == 0 {
		n2.Next = n2.Next.Next
	}
	if n == 1 {
		return head.Next
	}
	return head
}
func printList(head *ListNode) {
	n := head
	for n != nil {
		fmt.Println(n.Val)
		n = n.Next
	}
}

func main() {
	n1 := ListNode{1, nil}
	n2 := ListNode{2, nil}
	n3 := ListNode{3, nil}
	n4 := ListNode{4, nil}
	n5 := ListNode{5, nil}
	n1.Next = &n2
	n2.Next = &n3
	n3.Next = &n4
	n4.Next = &n5

	//printList(&n1)
	printList(removeNthFromEnd(&n1, 5))
}
