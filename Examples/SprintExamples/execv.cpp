#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<list>

using namespace std;

int main()
{
	
	cout<<"The begining"<<endl;
	if(fork()==0)
	{
//	sleep(1);
//	char* cmd="netstat";
//	char *args[]={"netstat","-r",NULL};

	int file =open("myFile.txt",O_WRONLY | O_CREAT,0777);

//	int status=execvp(cmd,args);
	cout<<"in Child"<<endl;
	int file2=dup2(file,STDOUT_FILENO);
	close(file);
	
		char* cmd="netstat";
		char *args[]={"netstat","-r",NULL};
		int status=execvp(cmd,args);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(0);
		fstream fs;
		list <string> myList;
		fs.open("myFile.txt", ios::in|ios::out);
		string line;
		while(getline(fs,line))
		{
			myList.push_back(line);
		}
		cout<<"In list"<<endl;
		auto it=myList.begin();
		for(advance(it,2);it!=myList.end();it++)
		{
			cout<<*it<<endl;
		}
			
		
		cout<<"The End"<<endl;
	}
}
