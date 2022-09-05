#include<client.h>
#include<netstat_r.h>
#include<netstat_tcp.h>

Client :: Client()
{

}

void Client :: createSock()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd < 0)
		{
			cout<<"Error in connection"<<endl;
			exit(EXIT_FAILURE);
		}
}

void Client :: connectServer()
{
	memset(&server_addr, '\0', sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(ADDR);


	client_fd = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(client_fd < 0){
		cout<<"Error in connection"<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Connected to Server"<<endl;
}

void Client :: send_recv(string temp)
{
		if(sendto(sockfd, temp.c_str(), strlen(temp.c_str()),0,(struct sockaddr*)&server_addr, server_addr_len)<0)
		{
			perror("sendto() error");
			exit(EXIT_FAILURE);
		}

		if(temp=="disconnect")
		{
			close(sockfd);
			cout<<"Disconnected from server"<<endl;
			exit(EXIT_FAILURE);
		}
		else if(temp == "RT")
		{
			RoutingTable *rt;

			if(recvfrom(sockfd, &rt, sizeof(rt),0,(struct sockaddr*)&client_addr, (socklen_t*)&client_addr_len)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}

			rt->displayRoutingTable();
		}
		else if(temp == "TCP")
		{
			netstatTCP *tcp;

			if(recvfrom(sockfd, &tcp, sizeof(tcp),0,(struct sockaddr*)&client_addr, (socklen_t*)&client_addr_len)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}

			tcp->displayTCP_Table();
		}
		else{}
	
}

void Client :: closeSock()
{
	close(sockfd);
}

Client :: ~Client()
{

}