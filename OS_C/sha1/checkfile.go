package main

import (
	"crypto/sha1"
	"fmt"
	"io"
	"log"
	"os"
)

func checkfile(file string) {
	f, err := os.Open(file)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	h := sha1.New()
	if _, err := io.Copy(h, f); err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%x\n", h.Sum(nil))
}

func main() {
	file := os.Args[1]

	checkfile(file)
 }
