#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<fstream>
#include<sys/wait.h>

using namespace std;

class RoutingTable
{
	public :
		RoutingTable();
		void getRoutingTable();
		void storeRoutingTable();
		void displayRoutingTable();
		~RoutingTable();

	private :
		char *Destination;
		string Gateway;
		string Genmask;
		string Flags;
		string Mss;
		string Window;
		string irtt;
		string Iface;

		list <string> dataList;
		char data[20][20];

};
