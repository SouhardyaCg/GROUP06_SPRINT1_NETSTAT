#include<server.h>
#include<netstat_r.h>
#include<netstat_tcp.h>
#include<netstat_udp.h>
#include<netstat_listen.h>
#include<netstat_firefox.h>

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
				char buffer[30];

				if(recv(newsockfd,buffer,sizeof(buffer),0)<0)
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
					getRoutingTable();
					string data=storeRoutingTable();

					char buffData[SIZE];
					strcpy(buffData,data.c_str());
					if(send(newsockfd, buffData, sizeof(buffData),0)<0)
					{
						perror("send() error");
						exit(EXIT_FAILURE);
					}
				}
				else if(strcmp(buffer,"TCP")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					getTCP_Table();
					string data=storeTCP_Table();

					char buffData[SIZE];
					strcpy(buffData,data.c_str());
					if(send(newsockfd, buffData, sizeof(buffData), 0)<0)
					{
						perror("send() error");
						exit(EXIT_FAILURE);
					}
				}
				else if(strcmp(buffer,"UDP")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					getUDP_Table();
					string data=storeUDP_Table();

					char buffData[SIZE];
					strcpy(buffData,data.c_str());
					if(send(newsockfd, buffData, sizeof(buffData), 0)<0)
					{
						perror("send() error");
						exit(EXIT_FAILURE);
					}
					
				}
				else if(strcmp(buffer,"Listen")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					getListen();
					string data=storeListen();

					char buffData[SIZE];
					strcpy(buffData,data.c_str());
					if(send(newsockfd, buffData, sizeof(buffData), 0)<0)
					{
						perror("send() error");
						exit(EXIT_FAILURE);
					}

				}
				else if (strcmp(buffer,"firefox")==0)
				{
					cout<<"Client:"<<buffer<<endl;
					getFIREFOX_Table();
					string data=storeFIREFOX_Table();

					char buffData[1000000];
					strcpy(buffData,data.c_str());
					if(send(newsockfd, buffData, sizeof(buffData),0)<0)
					{
						perror("send() error");
						exit(EXIT_FAILURE);
					}
				}
			
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