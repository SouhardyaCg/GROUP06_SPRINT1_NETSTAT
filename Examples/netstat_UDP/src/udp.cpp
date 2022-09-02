#include<udp.h>

void getUDP_Table()
{
	
		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
		dup2(file,STDOUT_FILENO);
		close(file);
		char* cmd="netstat";
		char *args[]={"netstat","-un",NULL};	
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	
}

void storeUDP_Table(list<string> &dataList)
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

void netstatUDP :: displayUDP_Table()
{
	cout<<"-------------- Kernel TCP Table  ------------------"<<endl;
	cout<<"Proto : "<<Proto<<endl;
	cout<<"Recv-Q :"<<Recv<<endl;
	cout<<"Send-Q :"<<Send<<endl;
	cout<<"Local Address :"<<Local_Address<<endl;
	cout<<"Foreign Address :"<<Foreign_Address<<endl;
	cout<<"State :"<<State<<endl;
	cout<<"---------------The End --------------------------"<<endl;

}

netstatUDP::~netstatUDP()
{}
