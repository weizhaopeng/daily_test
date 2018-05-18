#include "zhou_socket_tcp.h"

#define max(a, b) (a > b? a : b)

static inline int data_send(FILE *fp, const int connfd);

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
	int 			   ret;
	socklen_t		   len = sizeof(struct sockaddr_in);
	struct sockaddr_in cli_addr;

	cli_addr.sin_family 		= AF_INET;
	cli_addr.sin_port   		= htons(SOCKPORT);
	//用地址转换函数将表达式转换成32位in_addr_t
	ret = inet_pton(AF_INET, "172.16.252.209", &cli_addr.sin_addr.s_addr);
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
	ret = connect(sock_fd, (struct sockaddr *)&cli_addr, sizeof(struct sockaddr));
	if (ret == -1) {
		perror("connect");
		return -1;
	}
	else 
		puts("连接成功\n");
	//TODO建立连接后的数据传输
	ret = data_send(stdin, sock_fd);
	if (ret == -1)
		return -1;
	else 
		return 0;
}

static inline int data_send(FILE *fp, const int connfd) {
	struct pollfd fds[3];
	nfds_t 		  fds_num = 3;
	int    		  timeout = 20;
	fds[0].fd 	  = fileno(fp);
	fds[0].events = POLLIN;
	fds[1].fd 	  = connfd;
	fds[1].events = POLLIN;
	fds[2].fd 	  = connfd;
	fds[2].events = POLLOUT;

	while (1) {
		ret = poll(fds, fds_num, timeout);
		if (ret == -1)
			return -1;
		if (fds[0].revent == POLLIN) {
			read(fds[0].fd, buf, 100);
			if (fds[2].revents == POLLOUT)
				write(fds[2].fd, buf, 100);
		}
		if (fds[1],revents == POLLIN) {
			read(fds[1].fd, buf, 100);
			write




		
/*
static inline int data_send(FILE *fp, const int connfd) {
	int    maxfd1 = max(fileno(fp), connfd)+1, ret;
	fd_set rset, wset;
	char   buf[100];
	struct timeval timeout = {
		.tv_sec  = 100,
		.tv_usec = 20
	};
	
	while (1) {
		FD_ZERO(&rset);
		FD_ZERO(&wset);
		FD_SET(fileno(fp), 	   &rset);
		FD_SET(fileno(stdout), &wset);
		FD_SET(connfd, 		   &rset);
		FD_SET(connfd, 		   &wset);

		ret = select(maxfd1, &rset, &wset, NULL, &timeout);
		if (ret == -1)
			return -1;

		if (FD_ISSET(fileno(fp), &rset)) {
			read(fileno(fp), buf, 80);
			if (FD_ISSET(connfd, &wset)) {
				write(connfd, buf, 80);
			}
		}
		bzero(buf, 100);

		if (FD_ISSET(connfd, &rset)) {
			ret = read(connfd, buf, 100);
			if (FD_ISSET(STDOUT_FILENO, &wset) > 0) {
				write(STDOUT_FILENO, buf, 100);
			}
		}
	}
	return 0;
}
*/

		
