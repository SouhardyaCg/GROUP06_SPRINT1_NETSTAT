#pragma once
#include        <iostream>
#include        <stdlib.h>
#include        <errno.h>
#include        <string.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <sys/wait.h>
#include        <fcntl.h>
#include        <unistd.h>
#include        <bits/stdc++.h>
#include        <stdarg.h>
#include        <string>
#include        <cstring>
//#define         MAX_BUF      1024
//#define         PORT         52341
#define         SIZE         1024
using namespace std;
//string func(string);

class Sock								//Class socket
{
	private:
		int listensocket;
		int new_socket;
		int connectionsocket;
		int binderror;
		int sd;
//		int protno;
//		string ipaddr;
		struct sockaddr_in serveraddr , clientaddr;
		char server_msg[SIZE];
		char client_msg[SIZE];
		int server_addr_len = sizeof(serveraddr);
		int client_addr_len = sizeof(clientaddr);

//		string buff;
	public:
//		MySocket() {
//			ipaddr = ;
//			protno = 8080;
//		}
//		MySocket(string, int); 
                Sock();
		void server();
		void serverReadWrite();
		void client();
		void clientReadWrite(string);
		string func(string);
		~Sock();

};
