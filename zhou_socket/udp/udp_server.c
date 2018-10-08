#include "udp_test.h"

int main(void) {
	struct sockaddr_in seraddr, cliaddr;
	socklen_t socklen = sizeof(struct sockaddr), 
		cliaddr_len = sizeof(struct sockaddr);
	char   buf[100] = {0}, buf_add[100] = {"message_send_from_server:"};
	int    connfd = 0, ret = 0;
	
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
	strncat(buf_add, buf, ret);
	ret = sendto(connfd, buf_add, strlen(buf_add), 0, (struct sockaddr*)&cliaddr, cliaddr_len);
	if (ret == -1) {
		perror("回执信息失败");
		return -1;
	}
	puts("信息回执成功");

	return 0;
}


