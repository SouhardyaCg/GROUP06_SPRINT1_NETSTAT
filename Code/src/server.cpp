#include<server.h>
#include<netstat_r.h>
#include<netstat_tcp.h>

Server :: Server()
{

}

void Server :: createSock()
{

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		cout<<"Error in connection"<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Server Socket is created successfully" <<endl;
}

void Server :: bindClient()
{
	memset(&server_addr, '\0', sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(ADDR);

	int ret =bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(ret < 0)
	{
		cout<<"Error in binding."<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Binded to port :"<<PORT<<endl;
}

void Server :: listenClient()
{
	if(listen(sockfd, 5) == 0)
	{
		cout<<"Listening...."<<endl;
	}
	else
	{
		cout<<"Error in Listening"<<endl;
	}

}

void Server :: send_recv()
{
	while(1)
	{
		newsockfd = accept(sockfd, (struct sockaddr*)&client_addr,(socklen_t*)&client_addr_len);
		if(newsockfd < 0)
		{
			exit(EXIT_FAILURE);
		}
		cout<<"Connection accepted."<<endl;

		if(fork() == 0)
		{
				close(sockfd);
				char buffer[1024];

				if(recvfrom(newsockfd,buffer,1024,0,(struct sockaddr*)&client_addr, (socklen_t*)&client_addr_len)<0)
				{
					perror("recvfrom() error");
					exit(EXIT_FAILURE);
				}


				if(strcmp(buffer,"disconnect")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					cout<<"Disconnected."<<endl;
					break;
				}
				else if(strcmp(buffer,"RT")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					if(sendto(newsockfd, RTdriver(), sizeof(RTdriver()), 0,(struct sockaddr*)&client_addr, client_addr_len)<0)
					{
						perror("sendto() error");
						exit(EXIT_FAILURE);
					}
				}
				else if(strcmp(buffer,"TCP")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					if(sendto(newsockfd, TCPdriver(), sizeof(TCPdriver()), 0,(struct sockaddr*)&client_addr, client_addr_len)<0)
					{
						perror("sendto() error");
						exit(EXIT_FAILURE);
					}

				}
				else
				{}
			
		}

	}

}

void Server :: closeSock()
{
	close(newsockfd);
}

Server :: ~Server()
{

}