#include<client.h>
#include<netstat_r.h>
#include<netstat_tcp.h>

int main()
{
	Client c;
	c.createSock();
	c.connectServer();
	cout<<"WELCOME To PortScanner Implementation using Netstat"<<endl;
	cout<<"->Following are the commands given :"<<endl;
	cout<<"->Enter RT for netstat -r"<<endl;
	cout<<"->Enter TCP for netstat -tan"<<endl;
	cout<<"->Enter UDP for netstat -uan"<<endl;
	cout<<"->Enter application for netstat -tanp | grep -i firefox"<<endl;
	cout<<"->Enter Listen for netstat -tanp | grep -i LISTEN"<<endl;
	cout<<"->Enter exit to exit code"<<endl;
	cout<<"->Enter disconnect to stop server"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Enter your Command :"<<endl;
	string temp;
	cin>>temp;
	if(temp!="RT"&&temp!="TCP"&&temp!="UDP"&&temp!="application"&&temp!="exit"&&temp!="disconnect")
	{
		cout<<"Invalid Choice"<<endl;
		exit(EXIT_FAILURE);
	}
	else if(temp=="exit")
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		c.send_recv(temp);
		c.closeSock();	
	}


}