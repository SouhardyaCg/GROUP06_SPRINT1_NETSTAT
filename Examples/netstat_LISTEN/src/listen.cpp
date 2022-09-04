#include<listen.h>
void getListen()
{
	int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
	dup2(file,STDOUT_FILENO);
	close(file);
	char* cmd="netstat";
	char *args[]={"netstat","-tanp|grep -i firefox",NULL};
	execvp(cmd,args);
	exit(EXIT_SUCCESS);
}

void storeListen(list<string> &dataList)
{
	fstream fs;
	fs.open("myFile.txt",ios::in|ios::out);
	if(!fs)
	{
		 cout<<"No such File"<<endl;
	}
	else
	{
		int count = 0;
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
listen :: listen()
{}

void listen :: setProto(char data[][20])
{
	Proto = data[0];
}
string listen :: getProto()
{
	return Proto;
}
void listen :: setRecv(char data[][20])
{
	Recv=data[1];
}
string listen :: getRecv()
{
	return Recv;
}
void listen :: setSend(char data[][20])
{
	 Send=data[2];
}
string listen :: getSend()
{
	return Send;
}
void listen :: setLocal_Address(char data[][20])
{
	Local_Address=data[3];
}
string listen :: getLocal_Address()
{
	return Local_Address;
}
void listen :: setForeign_Address(char data[][20])
{
	Foreign_Address=data[4];
}
string listen :: getForeign_Address()
{
	return Foreign_Address;
}
void listen :: setState(char data[][20])
{
	State=data[5];
}
string listen :: getState()
{
	return State;
}
void listen :: setOthers(char data[][20])
{
	Others=data[6];
}
string listen :: getOthers()
{
	return Others;
}
void listen :: displayListen()
{
	cout<<"-------------- Kernel TCP Table  ------------------"<<endl;
	cout<<"Proto : "<<Proto<<endl;
	cout<<"Recv-Q :"<<Recv<<endl;
	cout<<"Send-Q :"<<Send<<endl;
	cout<<"Local Address :"<<Local_Address<<endl;
	cout<<"Foreign Address :"<<Foreign_Address<<endl;
	cout<<"State :"<<State<<endl;
	cout<<"Others :"<<Others<<endl;
	cout<<"---------------The End --------------------------"<<endl;
}
listen ::~listen()
{}

