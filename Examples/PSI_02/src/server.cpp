#include<server.h>
#include<cmd.h>

server::server()
{

}

void server::serverFunc()
{
	memset(&server_addr,'\0',sizeof(server_addr));
	memset(client_msg, '\0' , sizeof(client_msg));

	socket_sfd = socket(AF_INET,SOCK_STREAM, 0);
	if(socket_sfd < 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout<<"server socket created "<<endl;

	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	//Binding the server socket
	sockBind = bind(socket_sfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(sockBind < 0)
	{
		perror("Binding failed ");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout<<"Binded the server socket successfully"<<endl;

	}

	//Listening to the clients
	if(listen(socket_sfd,5) < 0)
	{
		perror("listen() error");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout<<"Listening to the clients....."<<endl;
	}

	acceptClient = accept(socket_sfd, (struct sockaddr*)&client_addr, &len);
	if(acceptClient < 0)
	{
		perror("Accept error");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout<<"Accepted the client request"<<endl;

	}
}

void server::serverReadWrite()
{	
	memset(client_msg, '\0' , sizeof(client_msg));
	int re=recvfrom(acceptClient, client_msg, SIZE, 0 ,(struct sockaddr*)&client_addr,(socklen_t*)&len);
	if(re < 0 )
	{
		perror("RECV Error");
		exit(EXIT_FAILURE);
	}

//	memset(server_msg, '\0', sizeof(server_msg));

	if(strcmp(client_msg,"netstat -r")==0)
	{
		strcpy(server_msg,"Invalid Command");
		if(sendto(acceptClient, server_msg, strlen(server_msg), 0,(struct sockaddr*)&client_addr , len)<0 )
	        {
		           perror("Send error");
			   exit(EXIT_FAILURE);
		}
										   
	}
	else
	{
		RoutingTable rt;
		if(fork()==0)
		{
			rt.getRoutingTable();
		}
		else
		{
			wait(0);
			rt.storeRoutingTable();
			rt.setData();
			rt.setDestination();
			strcpy(server_msg,rt.getDestination().c_str());
			if(sendto(acceptClient, server_msg, strlen(server_msg), 0,(struct sockaddr*)&client_addr , len)<0 )
			{
					perror("Send error");
					exit(EXIT_FAILURE);
			}
//			memset(server_msg, '\0', sizeof(server_msg));
//			rt.setGateway();
//			strcpy(server_msg,rt.getDestination().c_str());
//			if(sendto(acceptClient, server_msg, strlen(server_msg), 0,(struct sockaddr*)&client_addr , len)<0 )
//			{
//				perror("Send error");
//				 exit(EXIT_FAILURE);
//			}
			
		}
		
	cout<<"Sent server message (" << server_msg <<" ) to client  \n"<<endl;

	}
	
	close(socket_sfd);
	shutdown(socket_sfd, SHUT_RDWR);
}
server::~server()
{

}
