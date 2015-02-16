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
	cmdbuf = (char *)malloc(BUF_SIZE);
	cmdbuf[BUF_SIZE] = '\0';

	char * user_ip;
	user_ip = malloc(20);
	user_ip = "0.0.0.0";

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
		printf("Using port number %d\n",port);
	}

	//wait for input
	while(strcmp(cmdbuf,"quit") != 0){
		printf("\nEnter command:");
	    scanf("%s", cmdbuf); //accept a command from user

	    if(strcmp(cmdbuf,"help") == 0){ //display help screen
	    	printf("Help~~~\n");
	    }

	    else if(strcmp(cmdbuf,"myip") == 0){ //display user IP address
	    	printf("Your IP Address: %s\n",user_ip);
	    }

	    else if(strcmp(cmdbuf,"myport") == 0){
	    	printf("Current listening port: %i\n", port);
	    }

	}


	return 0;
}
