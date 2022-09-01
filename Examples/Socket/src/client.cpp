#include<client.h>
#include<socket.h>

client::client()
{

}
void client::clientFunc()
{

	memset(&client_addr,0,sizeof(client_addr));

	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(PORT);
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	connection = connect(socketfd,(struct sockaddr*)&server_addr, sizeof(server_addr));
	if(connection < 0)
	{
		perror("Connect() error");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout<<"Connection Established"<<endl;

	}
}
void client::clientReadWrite()
{	
	string str ;
	cout<<"Enter a message :"<<endl;
	cin>>str;
	string s=(const char*)str.c_str();
	strcpy(client_msg , (const char*)s.c_str() );
	cout<<"Client message  : " <<client_msg <<endl;
	if(sendto(socketfd,client_msg,strlen(client_msg),0,(struct sockaddr*)&server_addr,len) < 0)
	{
		perror(" Send eror");
		exit(EXIT_FAILURE);
	}
	cout<<"Send  ( "<<client_msg<<" ) to the server "<<endl;
	sleep(1);
	if(recvfrom(socketfd, server_msg, sizeof(server_msg),0,(struct sockaddr*)&client_addr,(socklen_t*)&len)<0)
	{
		perror("Recv error");
		exit(EXIT_FAILURE);
	}
	cout <<"Recived from Server : "<<server_msg<<endl;
	close(socketfd);
}
client::~client()
{

}
