#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

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
		string Destination;
		string Gateway;
		string Genmask;
		string Flags;
		string MSS;
		string Window;
		string irtt;
		string Iface;

		list <string> dataList;
};
