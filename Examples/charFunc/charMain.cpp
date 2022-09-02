#include<iostream>
#include<unistd.h>
#include<cstring>

using namespace std;

void pdata(char [][10]);

int main()
{
	char data[8][10];


	for(int i=0;i<8;i++)
	{	
		strcpy(data[i],"hello");
	}

	pdata(data);
}

void pdata(char data[][10])
{
	for(int i=0;i<8;i++)
	{
		cout<<data[i]<<endl;
	}
}
