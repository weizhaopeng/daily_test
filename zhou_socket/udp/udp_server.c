#include "udp_test.h"

int main(void) {
	struct sockaddr_in seraddr, cliaddr;
	socklen_t socklen = sizeof(struct sockaddr), cliaddr_len = 0;
	char   buf[100] = {0}, *buf_add = "服务器回执信息：";
	int    connfd = 0, ret = 0, len = strlen(buf_add);
	
	//初始化地址变量
	seraddr.sin_family 		= AF_INET;
	seraddr.sin_port   		= htons(UDP_PORT);
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	puts("服务器地址初始化完成");

	//创建socket
	connfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (connfd == -1) {
		perror("socket创建失败");
		return -1;
	}
	puts("socket创建成功");

	//绑定地址
	ret = bind(connfd, (struct sockaddr*)&seraddr, socklen);
	if (ret == -1) {
		perror("绑定地址失败");
		return -1;
	}
	puts("绑定地址成功");

	//接受信息并发送
	ret = recvfrom(connfd, buf, 100, 0, (struct sockaddr*)&cliaddr, &cliaddr_len);
	if (ret == -1) {
		perror("接收信息失败");
		return -1;
	}
	printf("服务器接收到信息:%s\n%d\n", buf, len);
	strncat(buf+ret, buf_add, len);
	ret = sendto(connfd, buf, ret, 0, (struct sockaddr*)&cliaddr, cliaddr_len);
	if (ret == -1) {
		perror("回执信息失败");
		return -1;
	}
	puts("信息回执成功");

	return 0;
}


