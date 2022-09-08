#include<client.h>
#include<netstat_r.h>
#include<netstat_tcp.h>
#include<netstat_udp.h>
#include<netstat_listen.h>
#include<netstat_firefox.h>

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

		if(send(sockfd, temp.c_str(), strlen(temp.c_str()),0)<0)
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
			char buffData[SIZE];
			if(recv(sockfd, buffData, sizeof(buffData),0)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}
			string rtData=buffData;
			RTdriver(rtData);
			
		}
		else if(temp == "TCP")
		{
			char buffData[SIZE];
			if(recv(sockfd, buffData, sizeof(buffData),0)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}
			string tcpData=buffData;
			TCPdriver(tcpData);
		}
		else if(temp == "UDP")
		{
			char buffData[SIZE];
			if(recv(sockfd, buffData, sizeof(buffData),0)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}
			string udpData=buffData;
			UDPdriver(udpData);
			
		}
		else if(temp == "Listen")
		{
			char buffData[SIZE];
			if(recv(sockfd, buffData, sizeof(buffData),0)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}
			string listenData=buffData;
			listendriver(listenData);
		}
		else if (temp == "firefox")
		{
			char buffData[1000000];
			if(recv(sockfd, buffData, sizeof(buffData),0)<0)
			{
				perror("sendto() error");
				exit(EXIT_FAILURE);
			}
			string firefoxData=buffData;
			firefoxdriver(buffData);
			
		}
	
	
}

void Client :: closeSock()
{
	close(sockfd);
}

Client :: ~Client()
{

}