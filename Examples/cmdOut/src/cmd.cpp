#include<cmd.h>

RoutingTable::RoutingTable()
{}

void RoutingTable::getRoutingTable()
{
	
		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
		int file2=dup2(file,STDOUTNO);
		close(file);{
		char* cmd="netstat";
		char *args[]={"netstat","-r",NULL};	
		int status=execvp(cmd,args);
		exit(EXIT_SUCCESS);
	
}

void RoutingTable::storeRoutingTable()
{
	fstream fs;
	fs.open("myFile.txt",ios::in|ios::out);
	if(!fs)
	{
		cout<<"No such File"<<endl;
	}
	else
	{
		string line;
		while(getline(fs,line))
		{
			dataList.push_back(line);
		}
	}
	fs.close();
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
