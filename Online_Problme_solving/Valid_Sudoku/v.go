package main

import (
	"fmt"
)

func isValidSudoku(board [][]byte) bool {
	rowMap := make([]map[byte]int, 9)
	colMap := make([]map[byte]int, 9)
	boxMap := make([]map[byte]int, 9)
	for c:=0; c < 9; c++ {
		rowMap[c] = make(map[byte]int)
		colMap[c] = make(map[byte]int)
		boxMap[c] = make(map[byte]int)
	}
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			current := board[i][j]
			if current == '.' {
				continue
			}
			if _, er := rowMap[i][current]; !er {
				rowMap[i][current] = 1
			}else {
				return false
			}
			if _, el := colMap[j][current]; !el {
				colMap[j][current] = 1
			}else {
				return false
			}
			boxNumber := i/3 + j/3*3
			if _, eb := boxMap[boxNumber][current]; !eb {
				boxMap[boxNumber][current] = 1
			}else{
				return false
			}
		}
	}
	return true
}

func main() {
	s1 := [][]byte{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}

	fmt.Println(isValidSudoku(s1))

}
