#include "zhou_socket_cli.h"
#include "zhou_chat_cli.h"

int main(int argc, char *argv[])
{
	//初始化变量
	char *server_ip = argv[1];
	int   port = SIN_PORT;
	int   ret, connfd;
	//创建tcp连接
	connfd = zhou_socket_cli(server_ip, port);
	if (connfd < 0) {
		perror("connect:");
		return -1;
	}
	//客户端和服务器进行数据交换
	ret = zhou_chat_cli(stdin, connfd);
	if (ret < 0) {
		perror("chat:");
		return -1;
	}
	//内存进行回收，文件描述符进行回收
	ret = zhou_socket_free(connfd);
	if (ret < 0) {
		perror("close");
		return -1;
	}
	return 0;
}

