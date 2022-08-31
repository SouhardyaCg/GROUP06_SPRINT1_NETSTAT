#include<cmd.h>

RoutingTable::RoutingTable()
{}

void RoutingTable::getRoutingTable()
{
	fstream fs;
	fs.open("myRT.txt",ios::in|ios::out);

	if(!fs)
	{
		cout<<"File do not exist"<<endl;
	}
	else
	{
		fs<<execvp(cmd,args);
	}
}

void RoutingTable::displayRoutingTable()
{
	cout<<"-------------- Kernel Routing Table  ------------------"<<endl;
	cout<<Destination<<endl;
	cout<<Gateway<<endl;
	cout<<Genmask<<endl;
	cout<<Flags<<endl;
	cout<<Mss<<endl;
	cout<<Window<<endl;
	cout<<irtt<<endl;
	cout<<Iface<<endl;
	cout<<"---------------The End --------------------------"<<endl;

}

RoutingTable::~RoutingTable()
{}
