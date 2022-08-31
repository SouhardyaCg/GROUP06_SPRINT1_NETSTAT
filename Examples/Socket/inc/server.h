#include<iostream>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 52341
#define MAXBUFF 1024

using namespace std;

class server()
{

	private:
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
		void serverReadWrite();
		~server() //Destructor
};
