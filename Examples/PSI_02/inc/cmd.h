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
#include<sstream>
#include<cstring>

using namespace std;

class RoutingTable
{
	public :
		RoutingTable();
		void getRoutingTable();
		void storeRoutingTable();
		void displayRoutingTable();
		void setData();
		void setDestination();
		string getDestination();
		void setGateway();
		string getGateway();
		void setGenmask();
		string getGenmask();
		void setFlags();
		string getFlags();
		void setMss();
		string getMss();
		void setWindow();
		string getWindow();
		void setirtt();
		string getirtt();
		void setIface();
		string getIface();
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
