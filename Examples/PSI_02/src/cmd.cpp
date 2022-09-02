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
<<<<<<< HEAD
		Destination.append(strcat(data[i]," "));
=======
		Destination.append(strcat(data[i],"  "));
>>>>>>> fb0010ba5df7005943829d189f92fa76de1949d4
	}
}
string RoutingTable :: getDestination()
{
	return Destination;
<<<<<<< HEAD
=======
}
void RoutingTable :: setGateway()
{
	for(int i=1;i<dataList.size()*8;i+=8)
	{
		Gateway.append(strcat(data[i],"  "));
	}
}
string RoutingTable :: getGateway()
{
	return Gateway;
>>>>>>> fb0010ba5df7005943829d189f92fa76de1949d4
}


void RoutingTable :: setGateway()
{
	for(int i=1;i<dataList.size()*8;i+=8)
	{
		Gateway.append(strcat(data[i]," "));
	}
}
string RoutingTable :: getGateway()
{
	return Gateway;
}


void RoutingTable :: setGenmask()
{
	for(int i=2;i<dataList.size()*8;i+=8)
	{
		 Genmask.append(strcat(data[i]," "));
	}
}

string RoutingTable :: getGenmask()
{
	return Genmask;
}

void RoutingTable :: setFlags()
{
	for(int i=3;i<dataList.size()*8;i+=8)
	{
		Flags.append(strcat(data[i]," "));
	}
}

string RoutingTable :: getFlags()
{
	return Flags;
}

void RoutingTable :: setMss()
{
	for(int i=4;i<dataList.size()*8;i+=8)
	{
		Mss.append(strcat(data[i]," "));
	}
}
string RoutingTable :: getMss()
{
	return Mss;
}

void RoutingTable :: setWindow()
{
	for(int i=5;i<dataList.size()*8;i+=8)
	{
		Window.append(strcat(data[i]," "));
	}
}
string RoutingTable :: getWindow()
{
	return Window;
}


void RoutingTable :: setirtt()
{
	for(int i=6;i<dataList.size()*8;i+=8)
	{
		 irtt.append(strcat(data[i]," "));
	}
}
string RoutingTable :: getirtt()
{
	return irtt;
}

void RoutingTable :: setIface()
{
	for(int i=7;i<dataList.size()*8;i+=8)
	{
		Iface.append(strcat(data[i]," "));
	}
}
string RoutingTable :: getIface()
{
	return Iface;
}



void RoutingTable :: displayRoutingTable()
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
