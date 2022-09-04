#pragma once
#include        <iostream>
#include        <stdlib.h>
#include        <errno.h>
#include        <string.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <sys/wait.h>
#include        <fcntl.h>
#include        <unistd.h>
#include        <bits/stdc++.h>
#include        <stdarg.h>
#include        <string>
#include        <cstring>
using namespace std;
class student 
{
	private:
		string name;
		int Class;
	public:
		student();
		void setName(string);
		string getName();
		void setClass(int);
		int getClass();
		void display();
		~student();

};
student* returnObj();

student* returnObj()
{
	student* s = new student[3];
	s[0].setName("Urvashi");
	s[1].setName("Uhsdf");
	s[2].setName("ihdnfv");
	s[0].setClass(12);
	s[1].setClass(12);
	s[2].setClass(8);
	return s;
}

student::student()
{}


void student :: setName(string str)
{
	name = str;
}
string student :: getName()
{
	return name;
}
void student :: setClass(int cls)
{
	Class = cls;
}
int student :: getClass()
{
	return Class;
}
void student :: display()
{
	student *s;
	s = returnObj();
	for(int i=0; i<3; i++)
	{
		cout<<"for object "<<i+1<<endl;
		cout<<s[i].name<<endl;
		cout<<s[i].Class<<endl;
	}
}

student :: ~student()
{
}


