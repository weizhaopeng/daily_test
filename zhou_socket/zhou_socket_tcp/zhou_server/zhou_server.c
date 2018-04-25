#include "zhou_chat_ser.h"
#include "zhou_socket_ser.h"

int connfd;
int listenfd;

int main(int argc, char *argv[], char *envp[])
{
	//创建当前服务器socket和客户端的存储地址端口结构
	struct sockaddr_in serv_addr;
	socklen_t		   serv_socklen = sizeof(struct sockaddr_in);
	
	bzero(&serv_addr, len);
	serv_addr.sin_family 	  = AF_INET;
	serv_addr.sin_port	 	  = htons(SOCKPROT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	struct sockaddr_in cli_addr;
	socklen_t		   cli_socklen;

	connfd = zhou_socket_ser(&serv_addr, &serv_socklen,
			&cli_addr, &cli_socklen);
	if (connfd == -1) {
		perror("tcp connect");
		return -1;
	}

	pid_t pid;
	int   ret;

	chat_pid = fork();
	if (chat_pid == 0) {
		close(listenfd);
		ret = zhou_chat_ser(connfd);
		if (ret < 0) {
			perror("chat");
			return -1;
		}
	}
	close(connfd);
	return 0;
}
