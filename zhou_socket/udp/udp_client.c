#include "udp_test.h"

int main(void) {
	int  	  ret = 0, connfd = 0;
	char 	  buf[100] = {0};
	socklen_t seraddr_len = sizeof(struct sockaddr_in);
	struct sockaddr_in seraddr;
	//初始化地址
	seraddr.sin_family = AF_INET;
	seraddr.sin_port   = htons(UDP_PORT);
	ret = inet_pton(AF_INET, SERVER_IP, &(seraddr.sin_addr.s_addr));
	if (ret == -1) {
		perror("地址转换失败");
		return 1;
	}
	else if (ret == 0) {
		puts("地址格式错误");
		return 1;
	}
	puts("地址初始化成功");
	//创建socket
	connfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (connfd == -1) {
		perror("socket创建失败");
		return 1;
	}
	puts("socket创建成功");
	
	//创建并发送信息
	puts("*******请输入要发送的信息:*******\n");
	scanf("%s", buf);
	
	ret = sendto(connfd, buf, strlen(buf), 0, 
		(struct sockaddr *)(&seraddr), seraddr_len);
	if (ret == -1) {
		perror("发送信息出错");
		return -1;
	}
	puts("信息已发送");
	
	ret = recvfrom(connfd, buf, 100, 0, (struct sockaddr *)(&seraddr), 
		&seraddr_len);
	if (ret == -1) {
		perror("未接收到回执信息");
		return -1;
	}
	puts("回执信息已接收");

	return 0;
}

