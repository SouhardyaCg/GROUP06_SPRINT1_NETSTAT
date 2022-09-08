#include<netstat_tcp.h>

void getTCP_Table()
{
	if(fork()==0)
	{
	
		int file=open("tcpFile.txt",O_WRONLY | O_CREAT,0777);
		dup2(file,STDOUT_FILENO);
		close(file);
		char* cmd="netstat";
		char *args[]={"netstat","-tan",NULL};	
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	}
	
}

string storeTCP_Table()
{
	fstream fs;
	string totalData;
	fs.open("tcpFile.txt",ios::in|ios::out);
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
void TCPdriver(string tcpData)
{
		list<string> myData;
		char data[6][20];

		string record;
		stringstream str(tcpData);
		while(getline(str,record,'|'))
		{
			myData.push_back(record);
		}

		int size=myData.size();
		int i=0;
		netstatTCP tcp[size];

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
			tcp[i].setProto(data);
			tcp[i].setRecv(data);
			tcp[i].setSend(data);
			tcp[i].setLocal_Address(data);
			tcp[i].setForeign_Address(data);
			tcp[i].setState(data);

			i++;
		}
	for(int i=0;i<size;i++)
	{
		cout<<"-------------- Kernel TCP Table Dataset "<<i+1<<" ------------------"<<endl;
		cout<<"Proto : "<<tcp[i].getProto()<<endl;
		cout<<"Recv-Q :"<<tcp[i].getRecv()<<endl;
		cout<<"Send-Q :"<<tcp[i].getSend()<<endl;
		cout<<"Local Address :"<<tcp[i].getLocal_Address()<<endl;
		cout<<"Foreign Address :"<<tcp[i].getForeign_Address()<<endl;
		cout<<"State :"<<tcp[i].getState()<<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
	}
}

netstatTCP :: netstatTCP()
{}

void netstatTCP :: setProto(char data[][20])
{
	Proto=data[0];	
}
string netstatTCP :: getProto()
{
	return Proto;
}
void netstatTCP :: setRecv(char data[][20])
{
	Recv=data[1];
}
string netstatTCP :: getRecv()
{
	return Recv;
}
void netstatTCP :: setSend(char data[][20])
{
	Send=data[2];
}
string netstatTCP :: getSend()
{
	return Send;
}
void netstatTCP :: setLocal_Address(char data[][20])
{
	Local_Address=data[3];
}
string netstatTCP :: getLocal_Address()
{
	return Local_Address;
}
void netstatTCP :: setForeign_Address(char data[][20])
{
	Foreign_Address=data[4];
}
string netstatTCP :: getForeign_Address()
{
	return Foreign_Address;
}
void netstatTCP :: setState(char data[][20])
{
	State=data[5];
}
string netstatTCP :: getState()
{
	return State;
}

netstatTCP::~netstatTCP()
{}
