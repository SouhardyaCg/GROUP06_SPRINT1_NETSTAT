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
	char data[20][20];
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
		char *args[]={"netstat","-tanp",NULL};
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
		int i=0;
		for(auto it=myList.begin();it!=myList.end();it++)
		 {
			string str=*it;
			stringstream st(str);
			string temp;
			while(st)											       
		       	{
				st>>temp;
				if(st)
			 	{
	//				strcpy(data[i],temp.c_str());
					i++;
				}
			}
				
																
		 }		
		
		for(int i=2;i<myList.size()*8;i+=8)
		{
	//		cout<<data[i]<<endl;
		}
		cout<<"The End"<<endl;
	}
}
