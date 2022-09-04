#include <Socket.h>
#include <header.h>
int main()
{
	int sockfd;
	struct sockaddr_in server_addr, client_addr;

	char server_msg[SIZE];
	char client_msg[SIZE];

	int server_addr_len = sizeof(server_addr);
	int client_addr_len = sizeof(client_addr);

	memset(server_msg,'\0',sizeof(server_msg));
	memset(client_msg,'\0',sizeof(client_msg));

	sockfd =socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(sockfd < 0)
	{

		perror("socket() error");
		exit(EXIT_FAILURE);
	}

	cout<<"Client Socket is created"<<endl;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORTNO);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	cout<<"Client done with the bind"<<endl;
	cout<<"Enter msg for server:"<<endl;
	string cmsg;
	getline(cin,cmsg);
	strcpy(client_msg,(const char*)cmsg.c_str());



	if(sendto(sockfd, client_msg, strlen(client_msg), 0,
				(struct sockaddr*)&server_addr, server_addr_len)<0)
	{
		perror("sendto() error");
		exit(EXIT_FAILURE);
	}

	cout<<"sent to Server:"<<client_msg<<endl;
	student *s;

	if(recvfrom(sockfd, &s, sizeof(s), 0,
			(struct sockaddr*)&client_addr, (socklen_t*)&client_addr_len)<0)
	{
		perror("sendto() error");
		exit(EXIT_FAILURE);
	}

	s->display();

	close(sockfd);
	return 0;
}
