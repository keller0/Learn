package main

import (
	"io"
	"log"
	"net"
	"os"
)
func main() {
	addr, err := net.ResolveTCPAddr("tcp", "localhost:8888")
	if err != nil {
		log.Fatal(err)
	}
	conn, err := net.DialTCP("tcp", nil, addr)
	if err != nil {
		log.Fatal(err)
	}
	done := make(chan int)
	defer func() {
		conn.CloseWrite()
		<-done
	}()
	go func() {
		io.Copy(os.Stdout, conn) //ignoring err
		log.Println("done")
		conn.CloseRead()
		done <- 1
	}()
	mustCopy(conn, os.Stdin)
}

func mustCopy(dst io.Writer, src io.Reader) {
	if _, err := io.Copy(dst, src); err != nil {
		log.Fatal(err)
	}
}
