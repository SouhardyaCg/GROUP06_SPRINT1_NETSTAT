#include<client.h>
#include<netstat_r.h>
#include<netstat_tcp.h>
#include<netstat_udp.h>
#include<netstat_listen.h>
#include<netstat_firefox.h>


int main()
{
	
	Client c;
	c.createSock();
	c.connectServer();
	cout<<"\n";
	cout<<"------------WELCOME To PortScanner Implementation using Netstat-----------"<<endl;
	cout<<"\n";
	cout<<"\t\tFollowing are the commands given :"<<endl;
	cout<<"\t\tEnter RT for netstat -r"<<endl;
	cout<<"\t\tEnter TCP for netstat -tan"<<endl;
	cout<<"\t\tEnter UDP for netstat -uan"<<endl;
	cout<<"\t\tEnter Firefox for netstat -tanp | grep -i firefox"<<endl;
	cout<<"\t\tEnter Listen for netstat -tanp | grep -i LISTEN"<<endl;
	cout<<"\t\tEnter exit to exit code"<<endl;
	cout<<"\n";
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"Enter your Command :";
	string temp;
	cin>>temp;
	if(temp!="RT"&&temp!="TCP"&&temp!="UDP"&&temp!="Listen"&&temp!="Firefox"&&temp!="exit")
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
	cl.close(); //closing global logFile
}

