#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char name[1024];
	char buffer1[1024];
	char time_buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n");

	printf("What is your name\n");
	fgets(name, sizeof(name), stdin);
	send(clientSocket, name, strlen(name), 0);
	printf("Welcome %s Below are the option you can perform:",name);
	int n;

	while(1){
		printf("\n1.Set time zone ( IST, UST, etc)\n2.Get current time\n3.Exit\n");
		fgets(buffer, sizeof(buffer), stdin);
		int m=(int) buffer[0];

		//for Setting time Zone
		if(m==49)
		{
			printf("Enter the time zone\n");
			fgets(time_buffer, sizeof(time_buffer), stdin);
			send(clientSocket, time_buffer, strlen(time_buffer), 0);
		}
		//For getting Current time
		else if(m==50)
		{
			send(clientSocket, buffer, strlen(buffer), 0);
			printf("client sent to server %s",buffer);
			buffer[0]= '\0';
			//n= recv(clientSocket, buffer1, 1024, 0);
			//printf("\nCurrent time is:   %s\n",buffer1);
			buffer1[0]= '\0';

		}
		//To exit the program
		else
		{
			exit(1);
		}
	}

	return 0;
}