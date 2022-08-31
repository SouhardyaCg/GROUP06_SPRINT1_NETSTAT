#include<server.h>
#include<socket.h>

server::server()
{

}

void server::serverFunc()
{
	memset(&server_addr,0,sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port - htons(PORT);
	server_addr.sin_add.s_addr = inet_addr("127.0.0.1");


	//Binding the server socket
	sockBind = bind(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
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
	if(listen(socketfd,5) < 0)
	{
		perror("listen() error");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout<<"Listening to the clients....."<<endl;
	}

	acceptClient = accept(socketfd, (struct sockaddr*)&client_addr, &len);
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
	while(1)
	{
		if(fork()==0)
		{	
			memset(client_msg, '\0' , sizeof(client_msg));
			int re=recvfrom(new_socket, client_msg, SIZE, 0 ,(struct sockaddr*)&clientaddr,(socklen_t*)&client_addr_len);

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

			if(sendto(new_socket, server_msg, strlen(server_msg), 0,(struct sockaddr*)&clientaddr , client_addr_len)<0 )
			{
				perror("Send error");
				exit(EXIT_FAILURE);
			}
			cout<<"Sent server message (" << server_msg <<" ) to client  \n"<<endl;
		}

	}
	close(new_socket);
	shutdown(socketfd, SHUT_RDWR);
}


server::~server()
{

}
