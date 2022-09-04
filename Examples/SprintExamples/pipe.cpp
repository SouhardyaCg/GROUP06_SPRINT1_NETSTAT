#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<list>
#include<sstream>
#include<cstring>

using namespace std;

int main()
{
	int fd[2];
	if(pipe(fd) == -1)
	{
		return 1;
	}
	cout<<"The begining"<<endl;

//	fd[0] =open("myFile.txt",O_WRONLY | O_CREAT,0777);
//	fd[1] =open("myFile1.txt",O_WRONLY | O_CREAT,0777);
	
	int pid1=fork();
	if(pid1==0)
	{
		cout<<"in Child1"<<endl;
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
		cout<<"in child2"<<endl;
		dup2(fd[0],STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);


		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
                dup2(file,STDOUT_FILENO);
                close(file);


		char *cmd="grep";
		char *args[]={"grep","-i","LISTEN",NULL};
		execvp(cmd,args);
		exit(EXIT_SUCCESS);
	}
		
		close(fd[0]);
		close(fd[1]);
		
		waitpid(pid1,NULL,0);
                waitpid(pid2,NULL,0);

//		int file=open("myFile.txt",O_WRONLY | O_CREAT ,0777);
//		dup2(file,STDOUT_FILENO);
//		close(file);
	
//		waitpid(pid1,NULL,0);
//		waitpid(pid2,NULL,0);

		fstream fs;
		list <string> myList;
		fs.open("myFile.txt", ios::in|ios::out);
		string line;
		int count=0;
		while(getline(fs,line))
		{
			count++;
			if(count>4)
				myList.push_back(line);
			else
				continue;
		}
		cout<<"In list"<<endl;
		for(auto it=myList.begin();it!=myList.end();it++)
		{
		//	cout<<*it<<endl;
		}
		
}
