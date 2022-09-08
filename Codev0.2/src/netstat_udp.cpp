#include<netstat_udp.h>

void getUDP_Table()
{
	if(fork()==0)
	{
	
		int file=open("udpFile.txt",O_WRONLY | O_CREAT ,0777);
		dup2(file,STDOUT_FILENO);
		close(file);
		char* cmd="netstat";
		char *args[]={"netstat","-uan",NULL};	
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	}
	
}

string storeUDP_Table()
{
	fstream fs;
	string totalData;
	fs.open("udpFile.txt",ios::in|ios::out);
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
void UDPdriver(string udpData)
{
	list<string> myData;
	char data[6][20];

		string record;
		stringstream str(udpData);
		while(getline(str,record,'|'))
		{
			myData.push_back(record);
		}

		int size=myData.size();
		int i=0;
		netstatUDP udp[size];

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
			udp[i].setProto(data);
			udp[i].setRecv(data);
			udp[i].setSend(data);
			udp[i].setLocal_Address(data);
			udp[i].setForeign_Address(data);
			udp[i].setState(data);

			i++;
		}

		for(int i=0;i<size;i++)
		{
			cout<<"-------------- Kernel UDP Table Dataset "<<i+1<<" ------------------"<<endl;
			cout<<"Proto : "<<udp[i].getProto()<<endl;
			cout<<"Recv-Q :"<<udp[i].getRecv()<<endl;
			cout<<"Send-Q :"<<udp[i].getSend()<<endl;
			cout<<"Local Address :"<<udp[i].getLocal_Address()<<endl;
			cout<<"Foreign Address :"<<udp[i].getForeign_Address()<<endl;
			cout<<"State :"<<udp[i].getState()<<endl;
			cout<<"-----------------------------------------------------"<<endl;
		}


}

netstatUDP :: netstatUDP()
{}

void netstatUDP :: setProto(char data[][20])
{
	Proto=data[0];	
}
string netstatUDP :: getProto()
{
	return Proto;
}
void netstatUDP :: setRecv(char data[][20])
{
	Recv=data[1];
}
string netstatUDP :: getRecv()
{
	return Recv;
}
void netstatUDP :: setSend(char data[][20])
{
	Send=data[2];
}
string netstatUDP :: getSend()
{
	return Send;
}
void netstatUDP :: setLocal_Address(char data[][20])
{
	Local_Address=data[3];
}
string netstatUDP :: getLocal_Address()
{
	return Local_Address;
}
void netstatUDP :: setForeign_Address(char data[][20])
{
	Foreign_Address=data[4];
}
string netstatUDP :: getForeign_Address()
{
	return Foreign_Address;
}
void netstatUDP :: setState(char data[][20])
{
	State=data[5];
}
string netstatUDP :: getState()
{
	return State;
}
netstatUDP::~netstatUDP()
{}
