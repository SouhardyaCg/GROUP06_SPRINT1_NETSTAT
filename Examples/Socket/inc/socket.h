#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

class socket()
{

	private:
		int socketfd;

	public:
		socket(); //constructor
		void socketCreate(); 
		~socket(); //Destructor
};
