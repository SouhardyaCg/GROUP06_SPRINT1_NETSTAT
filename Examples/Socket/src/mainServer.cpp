#include<server.h>
#include<socket.h>

int main()
{
	socketClass sock;
	sock.socketCreate();
	server s;
	s.serverFunc();
	s.serverReadWrite();

	return 0;

}
