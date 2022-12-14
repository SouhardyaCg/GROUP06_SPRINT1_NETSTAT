#include<netstat_firefox.h>

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

		int file=open("firefoxFile.txt",O_WRONLY | O_CREAT ,0777);
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

string storeFIREFOX_Table()
{
	fstream fs;
	string totalData;
	fs.open("firefoxFile.txt",ios::in|ios::out);
	if(!fs)
	{
		cout<<"No such File"<<endl;
	}
	else
	{
		string line;
		while(getline(fs,line))
		{
		
				totalData+=line+"|";
			
		}
	}
	fs.close();

	return totalData;
}

void firefoxdriver(string firefoxData)
{
	list<string> myData;
	char data[7][20];
	
		string record;
		stringstream str(firefoxData);
		while(getline(str,record,'|'))
		{
			myData.push_back(record);
		}
	
		int size=myData.size();
		int i=0;

		netstatFIREFOX nf[size];

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
			
			nf[i].setProto(data);
			nf[i].setRecv(data);
			nf[i].setSend(data);
			nf[i].setLocal_Address(data);
			nf[i].setForeign_Address(data);
			nf[i].setState(data);
			nf[i].setApplication(data);

			i++;
		}

		if(size==0)
		{
			cout<<"No such Application Running"<<endl;
		}
		else
		{
			for(int i=0;i<size;i++)
			{
				cout<<"-------------- Kernel TCP Table with Firefox application dataset "<<i+1<<" ------------------"<<endl;
				cout<<"Proto : "<<nf[i].getProto()<<endl;
				cout<<"Recv-Q :"<<nf[i].getRecv()<<endl;
				cout<<"Send-Q :"<<nf[i].getSend()<<endl;
				cout<<"Local Address :"<<nf[i].getLocal_Address()<<endl;
				cout<<"Foreign Address :"<<nf[i].getForeign_Address()<<endl;
				cout<<"State :"<<nf[i].getState()<<endl;
				cout<<"Application :"<<nf[i].getApplication()<<endl;
				cout<<"-------------------------------------------------------"<<endl;
			}
		}		
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
netstatFIREFOX::~netstatFIREFOX()
{}
