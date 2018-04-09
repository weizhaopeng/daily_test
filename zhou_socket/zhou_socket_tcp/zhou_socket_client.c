#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	int sock_fd;

	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd <= 0) {
		perror("error!");
		return -1;
	}

	struct sockaddr_in *sa = NULL;
	sa = malloc(sizeof(struct sockaddr_in));

	sa->sin_family 		= AF_INET;
	sa->sin_port   		= htons(80);
	//TODO:用地址转换函数将表达式转换成32位in_addr_t
	int ret;
	ret = inet_pton(AF_INET, "120.79.130.38", &sa->sin_addr.s_addr);
	//int inet_pton(int family, const char *ptr, void *sa);
	//const char *inet_ntop(int family, void *sa, char *ptr, socklen_t sock_len);
	if (ret < 0) {
		perror("error");
		return -1;
	}
	else if (ret = 0) {
		puts("表达式不正确");
	return 0;
	}

	ret = connect(sock_fd, (struct sockaddr*)sa, sizeof(struct sockaddr));
	if (ret = -1) {
		perror("error:");
		return -1;
	}
	
	ret = write(sock_fd, "nihao", sizeof(char)*6);
	if (ret == -1) {
		perror("error:");
		return -1;
	}
	
	if (sa != NULL) {
		free(sa);
		sa = NULL;
	}
	return 0;
}

