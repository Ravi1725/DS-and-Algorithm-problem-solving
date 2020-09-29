#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 4444
#define utc (0)  
#define cst (+8) 
#define ist (+5)
#define Lagos (+1)
#define london (+1)
#define cairo (+2)
#define paris (+2)     

int main(){

	int sockfd, ret;
	int n;
	 struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	char name[1024];
	char buffer1[1024];
	//char current_time[1024];
	char time_zone[1024];

	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}
  
    

	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){
			close(sockfd);

			while(1){
				n=recv(newSocket, name, 1024, 0);
				name[n]='\0';
				
				printf("new client connected name: %s\n", name);
				//send(newSocket, buffer, strlen(buffer), 0);
				bzero(name, sizeof(name));
				while(1)
				{
					n = recv(newSocket, buffer, 1024, 0);
					//buffer[n]='\0';
					printf("Time zone entered by client %s\n",buffer);
					strcpy(time_zone, buffer);
					//int m=(int)buffer[0];
					while(1)
					{
						n = recv(newSocket, buffer1, 1024, 0);
						buffer1[n]='\0';
						int m=(int)buffer1[0];
						//printf("%d",m);
						if(m==50)
						{
							//printf("%s %d",time_zone,strcmp(time_zone,"ist"));
							if(strcmp(time_zone,"ist")==0)
							{
						 
						    time_t current_time; 
						    struct tm* ptime; 
						    time_t now; 
						    time(&now); 
						    ptime = gmtime(&now);
							printf("IST :%2d:%02d:%02d\n",(ptime->tm_hour + ist) % 24, ptime->tm_min, ptime->tm_sec); 
							
						}
						}
					}
					
						//printf("Time zoned seted by client: %s",buffer);
					
					
					buffer[0]='\0';
			}
		}

	}
}

	close(newSocket);


	return 0;
}