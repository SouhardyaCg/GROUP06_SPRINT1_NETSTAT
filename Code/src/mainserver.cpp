#include<server.h>
#include<netstat_r.h>
#include<netstat_tcp.h>

int main()
{
	Server s;
	s.createSock();
	s.bindClient();
	s.listenClient();

	s.send_recv();
	s.closeSock();
}