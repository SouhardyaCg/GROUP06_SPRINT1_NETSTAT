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
#include<cstring>
#include<sstream>

using namespace std;
class listen
{
	public:
		listen();
		void setProto(char [][20]);
		string getProto();
		void setRecv(char [][20]);
		string getRecv();
		void setSend(char [][20]);
		string getSend();
		void setLocal_Address(char [][20]);
		string getLocal_Address();
		void setForeign_Address(char [][20]);
		string getForeign_Address();
		void setState(char [][20]);
		string getState();
		void setOthers(char [][20]);
		string getOthers();
		void displayListen();

		~listen();

	private:
		string Proto;
		string Recv;
		string Send;
		string Local_Address;
		string Foreign_Address;
		string State;
		string Others;
};
void getListen();
void storeListen(list<string> &);


