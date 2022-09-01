#include<stdio.h>
#include<unistd.h>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	char args[20][20];

	for(int i=0;i<10;i++)
	{
		strcpy(args[i],"Hello");
	}
	cout<<args[2]<<endl;
}
