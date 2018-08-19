package main

import "fmt"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil || (p.Val != q.Val) {
		return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
func printPreorder(t *TreeNode) {
	if t == nil {
		return
	}
	fmt.Println(t.Val)
	printPreorder(t.Left)
	printPreorder(t.Right)
}

func main() {
	n1 := TreeNode{1, &TreeNode{2, nil, nil}, &TreeNode{3, nil, nil}}
	n2 := TreeNode{1, &TreeNode{2, nil, nil}, &TreeNode{2, nil, nil}}
	printPreorder(&n1)
	printPreorder(&n2)
	fmt.Println(isSameTree(&n1, &n2))
}
