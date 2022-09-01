#include <sock.h>
Sock::Sock()
{ }
string Sock :: func(string str)
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

void Sock :: server()
{
	 memset(server_msg, '\0',  sizeof(server_msg));
	 memset(client_msg, '\0' , sizeof(client_msg));
	  
	 listensocket=socket(AF_INET,SOCK_STREAM, 0);
	 if(listensocket < 0)
	 {
		 perror("socket failed");
		 exit(EXIT_FAILURE);
	 }
	 cout<<"server socket created "<<endl;

	 serveraddr.sin_family = AF_INET;
	 serveraddr.sin_port= htons(4625/* atoi(argv[2]) */);
	 serveraddr.sin_addr.s_addr= inet_addr("127.0.0.1" /* argv[1] */);

	 binderror=bind(listensocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	 if(binderror < 0 )
	 {
		 perror("BIND failed");
		 exit(EXIT_FAILURE);
	 }
	 cout <<"Server done with binding"<<endl;

	 listen(listensocket , 4);
	 if(listen <0)
	 {
		 perror("Listen failed");
		 exit(EXIT_FAILURE);
	 }
	 cout<<"Listen Done"<<endl;
}
void Sock :: serverReadWrite()
{
	while(1)
	{
		new_socket=accept(listensocket,(struct sockaddr*)&clientaddr,
				(socklen_t*)&client_addr_len);
		if(new_socket < 0)
		{
			perror("Accept failed");
			exit(EXIT_FAILURE);
		}
		cout<<"Accept done"<<endl;
         if(fork()==0)
	 {
		 memset(client_msg, '\0' , sizeof(client_msg));
		 int re=recvfrom(new_socket, client_msg, SIZE, 0 ,
				 (struct sockaddr*)&clientaddr,(socklen_t*)&client_addr_len);
		 if(re < 0 )
		 {
			 perror("RECV Error");
			 exit(EXIT_FAILURE);
		 }
		 cout<<"Message from client is : "<<client_msg <<endl;
		 memset(server_msg, '\0', sizeof(server_msg));
		 
		 string s =func(client_msg);
      		 strcpy(server_msg,(const char*)s.c_str());
		  sleep(1);
		  
		  if(sendto(new_socket, server_msg, strlen(server_msg), 0,
					  (struct sockaddr*)&clientaddr , client_addr_len)<0 )
		  {
			  perror("Send error");
			  exit(EXIT_FAILURE);
		  }
		  cout<<"Sent server message (" << server_msg <<" ) to client  \n"<<endl;
 	 }
	}
	close(new_socket);
	
	shutdown(listensocket, SHUT_RDWR);
}

void Sock :: client()
{
	 memset(server_msg,'\0',sizeof(server_msg));
	 memset(client_msg,'\0',sizeof(client_msg));

	 sd=socket(AF_INET, SOCK_STREAM, 0);
	 if(sd < 0)
	 {
		 perror("\n Socket Error ");
		 exit(EXIT_FAILURE);
	 }
	 serveraddr.sin_family= AF_INET;
	 serveraddr.sin_port= htons(4625 /*atoi(argv[2])*/);
	 serveraddr.sin_addr.s_addr= inet_addr("127.0.0.1" /*argv[1] */);
	 if(inet_addr < 0)
	 {
		 perror("Invalid address");
		 exit(EXIT_FAILURE);
	 }
	 cout<<"valid addresss"<<endl;
	 int client_fd=connect(sd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	 if(client_fd < 0)
	 {
		 perror("Connection failed");
		 exit(EXIT_FAILURE);
	 }
	 cout<<"Connection Done"<<endl;
}
void Sock :: clientReadWrite(string str)
{
//	string s ;
//       strcpy(s ,(const char*)str.c_str());
	string s=(const char*)str.c_str();
	strcpy(client_msg , (const char*)s.c_str() );
	cout<<"Client message  : " <<client_msg <<endl;
       	if(sendto(sd,client_msg,strlen(client_msg),0,
				(struct sockaddr*)&serveraddr,server_addr_len) < 0)
	{
		perror(" Send eror");
		exit(EXIT_FAILURE);
	}
	cout<<"Send  ( "<<client_msg<<" ) to the server "<<endl;
	 sleep(1);

	  if(recvfrom(sd, server_msg, sizeof(server_msg),0,
			       	  (struct sockaddr*)&clientaddr,(socklen_t*)&client_addr_len)<0)
	  {
		  perror("Recv error");
		  exit(EXIT_FAILURE);
	  }
	  cout <<"Recived from Server : "<<server_msg<<endl;
	   close(sd);
}

Sock::~Sock()
{ }
