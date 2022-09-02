#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<errno.h>

#define PORT 52341
#define MAXBUFF 1024
#define SIZE 4096


using namespace std;

class server
{

	private:
		int socket_sfd;
		int acceptClient;
		int sockBind;
		int newsocket;

		struct sockaddr_in server_addr, client_addr;
		socklen_t len = sizeof(client_addr);

		char server_msg[SIZE];
		char client_msg[SIZE];


	public:
		server(); //constructor
		void serverFunc();
		//string func(string);
		void serverReadWrite();
		~server(); //Destructor
};
