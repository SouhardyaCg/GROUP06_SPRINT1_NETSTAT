#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class RoutingTable
{
	public :
		RoutingTable();
		void getRoutingTable;
		void displayRoutingTable;
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
};
