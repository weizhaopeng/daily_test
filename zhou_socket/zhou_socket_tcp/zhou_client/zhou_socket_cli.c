#include "zhou_socket_tcp.h"

int zhou_socket_cli(const char *server_ip)
{
	//creat client socket
	int connfd;
	connfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connfd < 0)
		return -1;

	//fill in the server's address
	struct sockaddr_in servaddr_in;
	int 			   ret;

	servaddr_in.sin_family 		= AF_INET;
	servaddr_in.sin_port	    = htons(SOCK_PORT);
	ret = inet_pton(AF_INET, server_ip, &servaddr_in.sin_addr.s_addr);
	if (ret < 0)
		return -1;
	else if (ret == 0) {
		printf("illegal ip address: %s\n", server_ip);
		return 0;
	}

	//connect the server
	ret = connect(connfd, (struct sockaddr*)servaddr_in, sizeof(servaddr_in));
	if (ret == -1)
		return -1;
	else
		return connfd;
}
	//call the client process
	pit_t chat_pid;

	chat_pid = fork();
	if (chat_pid == 0) {
		ret = chat_client(stdin, connfd);
		if (ret == -1)
			exit(-1);
		exit(0);
	}
	
	//close the fd
	close(connfd);
	return 0;
	}
}

		
