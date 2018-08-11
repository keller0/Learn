package main

var pm = map[byte]byte{
	')': '(',
	'}': '{',
	']': '[',
}

func isValid(s string) bool {
	l := len(s)
	if l == 0 || l%2 != 0 {
		return false
	}
	stack := []byte{s[0]}
	for i := 1; i < l; i++ {
		c := s[i]
		if c == '(' || c == '{' || c == '[' {
			stack = append(stack, c)
		} else if c == ')' || c == '}' || c == ']' {
			if stack[len(stack)-1] != pm[c] {
				return false
			}
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}

func main() {
	println(isValid("{{}}"))
	println(isValid(""))
	println(isValid("{{"))
	println(isValid("{{}"))
	println(isValid("{[]}"))
}
