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
#include<cstring>
#include<sstream>

using namespace std;

class RoutingTable
{
	public :
		RoutingTable();
		void getRoutingTable();
		void storeRoutingTable();
		void setData();
		void setDestination();
		string getDestination();
		void setGateway();
		string getGateway();
		void displayRoutingTable();
		~RoutingTable();

	private :
		string Destination;
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
