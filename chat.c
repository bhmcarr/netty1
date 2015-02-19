// chat.c - Brandon Carr - CSE 489 - Project 1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

const BUF_SIZE = 50;

int main(int argc, char* argv[]){
	
	//check for -s or -c flag
	int errno;
	char* cmdbuf;
	cmdbuf = malloc(BUF_SIZE);
	cmdbuf[BUF_SIZE] = '\0';


	char * user_ip;
	user_ip = malloc(20);
	user_ip = "0.0.0.0";

	typedef struct sockaddr_in {
		short int sin_family;			// Address family, AF_INET
		unsigned short int sin_port;	// Port number
		struct in_addr sin_addr;		// Internet address
		unsigned char sin_zero[8];		// sizeof(sockaddr) and all 0s
	}sockaddr_in;


//	flag1 = getopt(argc,argv,"SsCc");

	if(strcmp(argv[1],"s") == 0){
		printf("Starting in server mode...\n");
		//serverMode();
	}	
	else if(strcmp(argv[1],"c") == 0){
		printf("Starting in client mode...\n");
		//clientMode();
	}

	int port=0;

	if(argv[2]){
		sscanf(argv[2], "%i", &port);
	}

	// create server socket -- call socket() and return a file descriptor
	// of the new socket
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket < 0){
		printf("Cannot create socket.\n");
		return 0;
	}
	else
		printf("Socket creation successful (fd = %d)\n",server_socket);

	// declare server address struct
	sockaddr_in server_addr;

	// initialize server address struct
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(port);

	// print the port number (convert to readable format)
	printf("Port: %d:\n", ntohs(server_addr.sin_port));

	// bind address to socket
	printf("Binding server IP to socket...\n");
	if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
		printf("Bind failed.\n");
		return 0;
	}
	else
		printf("Bind successful!\n");



	//wait for input
	while(strcmp(cmdbuf,"exit") != 0){
		
		// clear command buffer
	    bzero(cmdbuf, sizeof(char[50]));

		printf("\nEnter command:");
	    scanf("%s", cmdbuf); //accept a command from user

	    if(strcmp(cmdbuf,"help") == 0){ //display help screen
	    	printf("Help~~~\n");
	    }

	    else if(strcmp(cmdbuf,"myip") == 0){ //display user IP address
	    	int temp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	    	sockaddr_in tempaddr;
	    	bzero(&tempaddr, sizeof(struct sockaddr_in));



	    	printf("Your IP Address: %s\n",user_ip);
	    }

	    else if(strcmp(cmdbuf,"myport") == 0){
	    	printf("Current listening port: %i\n", port);
	    }

	}


	return 0;
}
