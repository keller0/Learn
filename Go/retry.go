package main

import (
	"fmt"
	"log"
	"time"
)


func main() {
	retry := 0
	for {
		if true{
			if retry > 10 {
				log.Fatal("aa")
			}
			fmt.Println("retry: ", retry)
			retry++
			time.Sleep(time.Second *1)
			continue
		}
		break
	}
	
}
