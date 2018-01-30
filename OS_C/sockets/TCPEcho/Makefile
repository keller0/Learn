server : TCPEchoServer.o HandleTCPClient.o DieWithError.o
	cc -Wall -g -o echo-server TCPEchoServer.o HandleTCPClient.o DieWithError.o

client : TCPEchoClient.o DieWithError.o
	cc -Wall -g -o echo-client TCPEchoClient.o DieWithError.o

TCPEchoServer.o : TCPEchoServer.c TCPEcho.h
	cc -c TCPEchoServer.c
TCPEchoClient.o : TCPEchoClient.c TCPEcho.h
	cc -c TCPEchoClient.c
HandleTCPClient.o : HandleTCPClient.c TCPEcho.h
	cc -c HandleTCPClient.c
DieWithError.o : DieWithError.c TCPEcho.h
	cc -c DieWithError.c
clean :
	rm TCPEchoServer.o HandleTCPClient.o DieWithError.o TCPEchoClient.o \
		echo-server echo-client
