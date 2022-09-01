#include<socket.h>

socketClass::socketClass()
{

}
void socketClass::socketCreate()
{
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd < 0)
	{
		perror("Error in socket creation ");
		exit(EXIT_FAILURE);
	}

}

socketClass::~socketClass()
{

}
