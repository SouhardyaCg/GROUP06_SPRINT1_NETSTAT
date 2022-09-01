#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<errno.h>

#ifndef _socketClass_H
#define _socketClass_H


using namespace std;

class socketClass
{

	protected:
		int socketfd;

	public:
		socketClass(); //constructor
		void socketCreate(); 
		~socketClass(); //Destructor
};
#endif
