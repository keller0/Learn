#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"TCPEcho.h"

#define RCVBUFSIZE 32

int main(int argc, char *argv[])
{
  int sock;
  struct sockaddr_in echoServAddr;
  unsigned short echoServPort;
  char *servIP;
  char *echoString;
  char echoBuffer[RCVBUFSIZE];
  unsigned int echoStringLen;
  int bytesRcvd, totalBytesRcvd;

  if ((argc < 3) || (argc > 4))
	{
	  fprintf(stderr,"Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n",argv[0]);
	  exit(1);
	}

  servIP = argv[1];
  echoString = argv[2];

  if (argc == 4)
	echoServPort = atoi(argv[3]);
  else
	echoServPort = 7;

  /* Creat a reliable, stream socket using TCP */
  if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	DieWithError("socket() failed");

  /* Construct the server address structure */
  memset(&echoServAddr, 0, sizeof(echoServAddr));
  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = inet_addr(servIP);
  echoServAddr.sin_port = htons(echoServPort);

  /* Establish the connection to the echo server */
  if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
	DieWithError("connext() failed");

  echoStringLen = strlen(echoString);

  /* Send the string to the server */
  if (send(sock, echoString, echoStringLen, 0) != echoStringLen)
	DieWithError("send() sent a different number of bytes than expected");

  /* Receive the same string back from the server */
  totalBytesRcvd = 0;
  printf("Received: ");
  while (totalBytesRcvd < echoStringLen)
	{
	  /* Receive ip to buffer size (minus 1 to leave space for
		 a null terminator ) bytes from the sender */
	  if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE -1, 0)) <= 0)
		DieWithError("recv() failed or connection closed prematurely");
	  totalBytesRcvd += bytesRcvd;
	  echoBuffer[bytesRcvd] = '\0';
	  printf(echoBuffer);
	}

  printf("\n");
  close(sock);
  exit(0);
}
