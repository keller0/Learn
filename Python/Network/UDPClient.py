from socket import *
serverName = 'localhost'
serverPort = 7777
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = raw_input('input some lowercase sentence:')
clientSocket.sendto(message, (serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print modifiedMessage
clientSocket.close()
