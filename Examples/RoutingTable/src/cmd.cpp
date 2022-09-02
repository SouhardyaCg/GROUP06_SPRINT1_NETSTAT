#include<cmd.h>

void getRoutingTable()
{
	
		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
		int file2=dup2(file,STDOUT_FILENO);
		close(file);
		char* cmd="netstat";
		char *args[]={"netstat","-r",NULL};	
		int status=execvp(cmd,args);
		exit(EXIT_SUCCESS);
	
}

void storeRoutingTable(list<string> &dataList)
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

setData(list<string> &dataList , char **data)
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

RoutingTable :: RoutingTable()
{}

void RoutingTable :: setDestination(char data[][20])
{
	strcpy(Destination,data[0]);	
}
string RoutingTable :: getDestination()
{
	return Destination;
}
void RoutingTable :: setGateway(char data[][20])
{
	strcpy(Gateway,data[1]);
}
string RoutingTable :: getGateway()
{
	return Gateway;
}
void RoutingTable :: setGenmask(char data[][20])
{
	strcpy(Genmask,data[2]);
}
string RoutingTable :: getGenmask()
{
	return Genmask;
}
void RoutingTable :: setFlags(char data[][20])
{
	strcpy(Flags,data[3]);
}
string RoutingTable :: getFlags()
{
	return Flags;
}
void RoutingTable :: setMss(char data[][20])
{
	strcpy(Mss,data[4];
}
string RoutingTable :: getMss()
{
	return Mss;
}
void RoutingTable :: setWindow(char data[][20])
{
	strcpy(Window,data[5]);
}
string RoutingTable :: getWindow()
{
	return Window;
}
void RoutingTable :: setirtt(char data[][20])
{
	strcpy(irtt,data[6]);
}
string RoutingTable :: getirtt()
{
	return irtt;
}
void RoutingTable :: setIface(char data[][20])
{
	strcpy(Iface,data[7]);
}
string RoutingTable :: getIface()
{
	return Iface;
}

void RoutingTable :: displayRoutingTable()
{
	cout<<"-------------- Kernel Routing Table  ------------------"<<endl;
	cout<<"DESTINATION : "<<Destination<<endl;
	cout<<"GATEWAY :"<<Gateway<<endl;
	cout<<"GENMASK :"<<Genmask<<endl;
	cout<<"FLAGS :"<<Flags<<endl;
	cout<<"MSS :"<<Mss<<endl;
	cout<<"WINDOW :"<<Window<<endl;
	cout<<"IRTT :"<<irtt<<endl;
	cout<<"IFACE :"<<Iface<<endl;
	cout<<"---------------The End --------------------------"<<endl;

}

RoutingTable::~RoutingTable()
{}
