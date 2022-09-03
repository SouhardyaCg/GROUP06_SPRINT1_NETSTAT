#include<firefox.h>

void getFIREFOX_Table()
{
	
		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
		dup2(file,STDOUT_FILENO);
		close(file);
		char* cmd="netstat";
		char *args[]={"netstat","-tanp","|","grep","-i","firefox",NULL};	
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	
}

void storeFIREFOX_Table(list<string> &dataList)
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

netstatFIREFOX :: netstatFIREFOX()
{}

void netstatFIREFOX :: setProto(char data[][20])
{
	Proto=data[0];	
}
string netstatFIREFOX :: getProto()
{
	return Proto;
}
void netstatFIREFOX :: setRecv(char data[][20])
{
	Recv=data[1];
}
string netstatFIREFOX :: getRecv()
{
	return Recv;
}
void netstatFIREFOX :: setSend(char data[][20])
{
	Send=data[2];
}
string netstatFIREFOX :: getSend()
{
	return Send;
}
void netstatFIREFOX :: setLocal_Address(char data[][20])
{
	Local_Address=data[3];
}
string netstatFIREFOX :: getLocal_Address()
{
	return Local_Address;
}
void netstatFIREFOX :: setForeign_Address(char data[][20])
{
	Foreign_Address=data[4];
}
string netstatFIREFOX :: getForeign_Address()
{
	return Foreign_Address;
}
void netstatFIREFOX :: setState(char data[][20])
{
	State=data[5];
}
string netstatFIREFOX :: getState()
{
	return State;
}
void netstatFIREFOX :: setApplication(char data[][20])
{
	Application=data[6];
}
string netstatFIREFOX :: getApplication()
{
	return Application;
}

void netstatFIREFOX :: displayFIREFOX_Table()
{
	cout<<"-------------- Kernel TCP-FIREFOX Table  ------------------"<<endl;
	cout<<"Proto : "<<Proto<<endl;
	cout<<"Recv-Q :"<<Recv<<endl;
	cout<<"Send-Q :"<<Send<<endl;
	cout<<"Local Address :"<<Local_Address<<endl;
	cout<<"Foreign Address :"<<Foreign_Address<<endl;
	cout<<"State :"<<State<<endl;
	cout<<"Application :"<<Application<<endl;
	cout<<"---------------The End --------------------------"<<endl;

}

netstatFIREFOX::~netstatFIREFOX()
{}
