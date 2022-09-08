#include<netstat_r.h>

void getRoutingTable()
{
		if(fork()==0)
		{
			int file=open("rtFile.txt",O_WRONLY | O_CREAT ,0777);
			dup2(file,STDOUT_FILENO);
			close(file);
			char* cmd="netstat";
			char *args[]={"netstat","-r",NULL};	
			execvp(cmd,args);
			exit(EXIT_SUCCESS);
		}
		wait(0);	
}

string storeRoutingTable()
{
	fstream fs;
	string totalData;
	fs.open("rtFile.txt",ios::in|ios::out);
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
				totalData+=line+"|";
			else
				continue;
		}
	}
	fs.close();
	return totalData;
}

void RTdriver(string totalData)
{

	
	char data[8][20];
	list<string> myData;

	string record;
	stringstream str(totalData);
	while(getline(str,record,'|'))
	{
		myData.push_back(record);
	}
	
	int size=myData.size();
	int i=0;
	RoutingTable rt[size];

	for(auto it=myData.begin();it!=myData.end();it++)
	{
			string str=*it;
			stringstream st(str);
			string temp;
			int j=0;
			while(st)
			{
				st>>temp;
				if(st)
				{
					strcpy(data[j],temp.c_str());
					j++;
				}
			}
			rt[i].setDestination(data);
			rt[i].setGateway(data);
			rt[i].setGenmask(data);
			rt[i].setFlags(data);
			rt[i].setMss(data);
			rt[i].setWindow(data);
			rt[i].setirtt(data);
			rt[i].setIface(data);

			i++;
	}
	
	for(int i=0;i<size;i++)
	{
		cout<<"-------------- Kernel Routing Table DataSet "<<i+1<<"------------------"<<endl;
		cout<<"DESTINATION : "<<rt[i].getDestination()<<endl;
		cout<<"GATEWAY :"<<rt[i].getGateway()<<endl;
		cout<<"GENMASK :"<<rt[i].getGenmask()<<endl;
		cout<<"FLAGS :"<<rt[i].getFlags()<<endl;
		cout<<"MSS :"<<rt[i].getMss()<<endl;
		cout<<"WINDOW :"<<rt[i].getWindow()<<endl;
		cout<<"IRTT :"<<rt[i].getirtt()<<endl;
		cout<<"IFACE :"<<rt[i].getIface()<<endl;
		cout<<"----------------------------------------------"<<endl;
	}

}

RoutingTable :: RoutingTable()
{}

void RoutingTable :: setDestination(char data[][20])
{
	Destination=data[0];	
}
string RoutingTable :: getDestination()
{
	return Destination;
}
void RoutingTable :: setGateway(char data[][20])
{
	Gateway=data[1];
}
string RoutingTable :: getGateway()
{
	return Gateway;
}
void RoutingTable :: setGenmask(char data[][20])
{
	Genmask=data[2];
}
string RoutingTable :: getGenmask()
{
	return Genmask;
}
void RoutingTable :: setFlags(char data[][20])
{
	Flags=data[3];
}
string RoutingTable :: getFlags()
{
	return Flags;
}
void RoutingTable :: setMss(char data[][20])
{
	Mss=data[4];
}
string RoutingTable :: getMss()
{
	return Mss;
}
void RoutingTable :: setWindow(char data[][20])
{
	Window=data[5];
}
string RoutingTable :: getWindow()
{
	return Window;
}
void RoutingTable :: setirtt(char data[][20])
{
	irtt=data[6];
}
string RoutingTable :: getirtt()
{
	return irtt;
}
void RoutingTable :: setIface(char data[][20])
{
	Iface=data[7];
}
string RoutingTable :: getIface()
{
	return Iface;
}

RoutingTable::~RoutingTable()
{}
