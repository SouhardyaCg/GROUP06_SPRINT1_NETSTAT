#include <sock.h>
int main(int argc , char *argv[])
{
	Sock obj1;
//	obj1.client();
//	string s;

//	string str=argv[2];
	for(int i=1; i<argc ; i++)
	{
//	s=(const char*)argv[i].c_str();
	obj1.client();
		obj1.clientReadWrite(argv[i]);
	}

	return 0;
}
