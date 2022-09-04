#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444
using namespace std;

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		cout<<"[-]Error in connection"<<endl;
		exit(1);
	}
	cout<<"[+]Client Socket is created"<<endl;

	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		cout<<"[-]Error in connection"<<endl;
		exit(1);
	}
	cout<<"[+]Connected to Server.\n";

	
		cout<<"Client: \t";
		cin>>buffer;
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, ":exit") == 0){
			close(clientSocket);
			cout<<"[-]Disconnected from server"<<endl;
			exit(1);
		}

		if(recv(clientSocket, buffer, 1024, 0) < 0){
			cout<<"[-]Error in receiving data"<<endl;
		}else{
			cout<<"Server:" <<buffer<<endl;
		}
	

	return 0;
}
