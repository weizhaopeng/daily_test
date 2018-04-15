#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	//创建socket
	int sock_fd, ret =0;
	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0) {
		perror("creat socket");
		return -1;
	}

	//创建地址空间将本地IP地址和端口填入，默认是0的情况下使用通配地址和公用约定好的服务端口	
	struct sockaddr_in ser_addr, cli_addr;
	socklen_t 		   len = sizeof(struct sockaddr_in);;

	bzero(&ser_addr, len);
	ser_addr.sin_family 	 = AF_INET;
	ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ser_addr.sin_port		 = htons(SOCKPORT);

	//将服务器的地址和端口绑定到socket上
	ret = bind(sock_fd, (struct sockaddr*)&ser_addr, len);
	if (ret == -1) {
		perror("bind");
		return -1;
	}

	//对创建的socket（文件描述符）进行监控，成功返回0
	ret = listen(sock_fd, 5);
	if (ret == -1) {
		perror("error");
		return -1;
	}

	int         conn_fd;
	socklen_t   cli_addr_len;
	char   	    buf[20];
	pid_t		pid;

	while (1) {
		//接受的时候使用的地址是客户端的地址，会将接收到的客户端地址和端口填入传递的地址空间中，在被调函数中可以进行查看,注意长度传递的是地址
		conn_fd = accept(sock_fd, (struct sockaddr *)&cli_addr, &cli_addr_len);
		if (conn_fd == -1) {
			perror("accept");
			continue;
		}
		//ssize_t read(int fd, void *buf, size_t count);	EOF:return 0, error:return -1	>0:return the byte read
		//TODO:在连接之后进行的数据操作
		pid = fork();
		if (pid == 0) {
			//关闭子进程的监听描述符
			close(sock_fd);

			ret = read(conn_fd, buf, 20);
			if (ret == -1) {
				perror("read");
				exit(-1);
			}

			ret = write(conn_fd, buf+2, 10);
			if (ret == -1) {
				perror("write");
				exit(-1);
			}
			exit(0);
		}

		ret = close(conn_fd);
	}
	return 0;
}



		

