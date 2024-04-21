package main

import (
	"fmt"
	"os"
)

func main() {
	s, sep := "", ""
	for _, arg := range os.Args[1:] {
		s += sep + arg
		sep = ""
	}

	for i, arg := range os.Args[1:] {
		fmt.Printf("%v %v\n", i, arg)
	}
}
