#include<iostream>
#include<iostream>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<socket.h>

#define PORT 52341
#define MAXBUFF 1024

using namespace std;

class client::private socket
{
	private:
		int connection;

		struct sockaddr_in server_addr, client_addr;


	public:
		client(); //constructor
		void clientFunc();
		void clientReadWrite();
		~client(); //destructor
};
