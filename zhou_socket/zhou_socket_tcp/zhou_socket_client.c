#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	//创建客户端socket
	int sock_fd;
	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd <= 0) {
		perror("creat socket");
		return -1;
	}
	//填充服务器地址和端口
	int 			    ret;
	socklen_t			len = sizeof(struct sockaddr_in);
	struct sockaddr_in *cli_addr = NULL;

	cli_addr = malloc(sizeof(struct sockaddr_in));
	if (cli_addr == NULL) {
		perror("malloc cli_addr");
		return -1;
	}

	cli_addr->sin_family 		= AF_INET;
	cli_addr->sin_port   		= htons(18);
	//用地址转换函数将表达式转换成32位in_addr_t
	ret = inet_pton(AF_INET, "120.79.130.38", &cli_addr->sin_addr.s_addr);
//int inet_pton(int family, const char *ptr, void *cli_addr);
	//const char *inet_ntop(int family, void *cli_addr, char *ptr, socklen_t sock_len);
	if (ret < 0) {
		perror("address translate");
		return -1;
	}
	
	else if (ret = 0) {
		puts("表达式不正确");
		return 0;
	}

	//连接服务器套接字
	ret = connect(sock_fd, (struct sockaddr*)cli_addr, sizeof(struct sockaddr));
	if (ret = -1) {
		perror("connect");
		return -1;
	}
	
	ret = write(sock_fd, "nihao", sizeof(char)*6);
	if (ret == -1) {
		perror("write data");
		return -1;
	}
	
	if (cli_addr != NULL) {
		free(cli_addr);
		cli_addr = NULL;
	}
	return 0;
}

