#include <func.h>
string  func(string str)
{
	for(int i = 0; i<str.length() ; i++)
	{
		if(str[i] == 's')
		{
			str[i]='d';
		}
       }
	cout<<"String after Replacing empty Spaces  with ! ";
return str;
}
/*
int main(int argc , char *argv[])
{
for(int i =1; i<argc ;i++)
{
func(argv[i]);
}
}
*/

	
