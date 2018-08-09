package main

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 || len(strs[0]) == 0 {
		return ""
	}
	var i int
	for {
		var row int
		if len(strs[row]) <= i {
			return strs[0][:i]
		}
		char := strs[row][i]
		row++
		for row < len(strs) {
			if len(strs[row]) <= i || strs[row][i] != char {
				return strs[0][:i]
			}
			row++
		}
		i++
	}
}

func main() {
	arr := [][]string{
		{"flower", "flow", "flight"},
		{"", ""},
		{" ", ""},
		{"a"},
		{"a1", "a ", "a"},
	}
	for _, a := range arr {
		println(longestCommonPrefix(a))
	}

}
