#include<firefox.h>

void getFIREFOX_Table()
{
	
	int fd[2];
	if(pipe(fd) == -1)
	{
		return perror("pipe");
	}
	int pid1=fork();
	if(pid1==0)
	{
		dup2(fd[1],STDOUT_FILENO);

		close(fd[0]);
		close(fd[1]);

		char* cmd="netstat";
		char *args[]={"netstat","-tanp",NULL};
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	}
	int pid2=fork();
	if(pid2==0)
	{
		dup2(fd[0],STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);

		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
        dup2(file,STDOUT_FILENO);
        close(file);


		char *cmd="grep";
		char *args[]={"grep","-i","firefox",NULL};
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	}
		
		close(fd[0]);
		close(fd[1]);
		
		waitpid(pid1,NULL,0);
        waitpid(pid2,NULL,0);
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
		string line;
		while(getline(fs,line))
		{
		
				dataList.push_back(line);
			
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
	cout<<"-------------- Kernel TCP Table  ------------------"<<endl;
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
