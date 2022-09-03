#include<firefox.h>

int main()
{
	list<string> myData;
	char data[7][20];
	
	if(fork()==0)
	{
		getFIREFOX_Table();
	}
	else
	{
		wait(0);
		storeFIREFOX_Table(myData);
	
		int size=myData.size();
		int i=0;
		netstatFIREFOX obj[size];

		for(auto it=myData.begin();it!=myData.end();it++)
		{
			string str=*it;
			stringstream st(str);
			string temp;
			int j=0;
			while(st)
			{
				st>>temp;
				if(st)
				{
					strcpy(data[j],temp.c_str());
					j++;
				}
			}
			obj[i].setProto(data);
			obj[i].setRecv(data);
			obj[i].setSend(data);
			obj[i].setLocal_Address(data);
			obj[i].setForeign_Address(data);
			obj[i].setState(data);
			obj{i}.setApplication(data);

			i++;
		}
	
                
		for(int i=0;i<size;i++)
		{
			cout<<"Output for OBJECT "<<i<<endl;
			obj[i].displayFIREFOX_Table();
		}
	}
}
