#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include"TCPEcho.h"

#define RCVBUFSIZE 32

/* Error handling function */
void HandleTCPClient(int clntSocket)
{
  char echoBuffer[RCVBUFSIZE];
  int recvMsgSize;
  /* Buffer for echo string */
  /* Size of received message */
  /* Receive message from client */
  if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
	DieWithError("recv() failed") ;
  /* Send received string and receive again until end of transmission */
  while (recvMsgSize > 0)
	/* zero indicates end of transmission */
	{
	  /* Echo message back to client */
	  if (send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
		DieWithError("send() failed");
	  /* See if there is more data to receive */
	  if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
		DieWithError("recv() failed") ;
	}

  close(clntSocket);
}
