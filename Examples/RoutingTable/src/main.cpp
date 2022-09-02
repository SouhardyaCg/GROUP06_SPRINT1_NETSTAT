#include<cmd.h>

int main()
{
	list<string> myData;
	char data[8][20];
	
	if(fork()==0)
	{
		getRoutingTable();
	}
	else
	{
		wait(0);
		storeRoutingTable(myData);
	
		int size=myData.size();
		int i=0;
		RoutingTable obj[size];

		for(auto it=myData.begin();it!=myData.end();it++)
		{
			string str=*it;
			stringstream st(str);
			string temp;
			while(st)
			{
				st>>temp;
				if(st)
				{
				strcpy(data[i],temp);
				}
			}
			obj[i].setDestination(data);
			obj[i].setGateway(data);
			obj[i].setGenmask(data);
			obj[i].setFlags(data);
			obj[i].setMss(data);
			obj[i].setWindow(data);
			obj[i].setirtt(data);
			obj[i].setIface(data);

			i++;
		}
	
                
		for(int i=0;i<size;i++)
		{
			cout<<"Output for OBJECT "<<i<<endl;
			obj[i].displayRoutingTable();
		}
	}
}



