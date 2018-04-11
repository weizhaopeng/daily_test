#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	//创建socket
	int sock_fd;

	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0) {
		perror("error");
		return -1;
	}
	//创建地址空间将本地IP地址和端口填入，默认是0的情况下使用通配地址和公用约定好的服务端口	
	struct sockaddr_in *sa_in = NULL;

	sa_in = malloc(sizeof(struct sockaddr_in));
	if (sa_in == NULL) {
		perror("error");
		return -1;
	}
	sa_in->sin_family 	   = AF_INET;
	sa_in->sin_addr.s_addr = htonl(INADDR_ANY);
	sa_in->sin_port		   = htons(0);
	//发起对创建的socket进行监听
	int    listen_fd;
	struct sockaddr_in *cli_addr = NULL;
	cli_addr = malloc(sizeof(struct sockaddr_in));

	listen_fd = listen(sock_fd, 10);
	if (listen_fd == -1) {
		perror("error");
		if (sa_in)
			free(sa_in);
		return -1;
	}
	//通过对监听端口进行监听，用循环将listen_fd绑定上本地的地址和端口
	int   conn_fd, ret;
	int   len = sizeof(struct sockaddr);
	char *buf = malloc(sizeof(20));

	while (1) {
		//接受的时候使用的地址是客户端的地址，会将接收到的客户端地址和端口填入传递的地址空间中，在被调函数中可以进行查看,注意长度传递的是地址
		conn_fd = accept(listen_fd, (struct sockaddr *)cli_addr, &len);
		/*if (conn_fd == -1) {
			perror("error");
			if (sa_in)
				free(sa_in);
			if (cli_addr)
				free(cli_addr);
			return -1;
		}*/
		//ssize_t read(int fd, void *buf, size_t count);	EOF:return 0, error:return -1	>0:return the byte read
		ret = read(conn_fd, buf, 5);
		printf("%s", buf);

		ret = close(conn_fd);
	}
	if (sa_in)
		free(sa_in);
	if (cli_addr)
		free(cli_addr);
	return 0;
}



		

