#include<tcp.h>

void getTCP_Table()
{
	
		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
		dup2(file,STDOUT_FILENO);
		close(file);
		char* cmd="netstat";
		char *args[]={"netstat","-tan",NULL};	
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	
}

void storeTCP_Table(list<string> &dataList)
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

void netstatTCP :: displayTCP_Table()
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

netstatTCP::~netstatTCP()
{}
