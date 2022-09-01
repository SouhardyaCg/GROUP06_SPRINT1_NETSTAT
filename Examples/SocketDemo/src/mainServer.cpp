#include <sock.h>

int main(int argc , char *argv[])
{
	Sock obj;
	obj.server();
	obj.serverReadWrite();

	return 0;
}
