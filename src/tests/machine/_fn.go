package main

func fn0(a, b int) int {
	return a + b
}

func fn1(arr [5]int) int {
	return arr[1]
}

func main() {
	arr := [5]int{1, 2, 3, 4, 5}
	fn0(1, 2)
	fn1(arr)
}
