#include<cmd.h>

RoutingTable::RoutingTable()
{}

void RoutingTable::getRoutingTable()
{
	
		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
		int file2=dup2(file,STDOUT_FILENO);
		close(file);
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
		int count =0;
		string line;
		while(getline(fs,line))
		{
			count++;
			if(count>2)
				dataList.push_back(line);
			else
				continue;
		}
	}
	fs.close();

}

void RoutingTable :: setData()
{
	int i=0;
	for(auto it=dataList.begin();it!=dataList.end();it++)
	{
		string str=*it;
		stringstream st(str);
		string temp;
		while(st)
		{
			st>>temp;
			if(st)
			{
				strcpy(data[i],temp.c_str());
				i++;
			}
		}
	}

}
void RoutingTable :: setDestination()
{
	for(int i=0;i<dataList.size()*8;i+=8)
	{
		strcpy(Destination[i],data[i];
	}
}
void RoutingTable :: getDestination()
{
	return Destination[];
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
