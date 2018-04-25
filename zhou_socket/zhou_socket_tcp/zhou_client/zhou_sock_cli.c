#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	//creat client socket
	int connfd;
	connfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connfd < 0) {
		perror("socket create:");
		return -1;
	}

	//fill in the server's address
	struct sockaddr_in servaddr_in;
	int 			   ret;

	servaddr_in.sin_family 		= AF_INET;
	servaddr_in.sin_port	    = htons(SOCK_PORT);
	ret = inet_pton(AF_INET, server_ip,&servaddr_in.sin_addr.s_addr);
	if (ret < 0) {
		perror("use server address");
		return -1;
	}
	else if (ret == 0) {
		perror("address wrong");
		return 0;
	}

	//connect the server
	ret = connect(connfd, (struct sockaddr*)servaddr_in, sizeof(servaddr_in));
	if (ret == -1) {
		perror("connot connect");
		return -1;
	}
	
	//call the client process
	pit_t chat_pid;

	chat_pid = fork();
	if (chat_pid == 0) {
		ret = chat_client(connfd);
		if (ret == -1) {
			perror("chat");
			exit(-1);
		}
		exit(0);
	}
	
	//close the fd
	close(connfd);
	return 0;
	}
}

		
