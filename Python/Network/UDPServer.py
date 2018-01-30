from socket import *
serverPort = 7777
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print "The server is ready to receive"
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    print clientAddress
    print "send : " + message
    modifiedMessage = message.upper()
    serverSocket.sendto(modifiedMessage, clientAddress)
