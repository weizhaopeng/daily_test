#include "zhou_socket_ser.h"

int zhou_socket_ser(const struct sockaddr_in *serv_addr, socklen_t *serv_socklen, struct sockaddr_in *cli_addr, socklen_t *cli_socklen)
{
	//定义本地socket
	int listenfd;
	int connfd;

	listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenfd < 0)
		return -1;

	//将服务器地址端口绑定到listenfd上
	int ret;
	
	ret = bind(listenfd, (struct sockaddr*)serv_addr, *serv_socklen);
	if (ret < 0)
		return -1;

	//对绑定的socket进行监听
	ret = listen(listenfd, 10);
	if (ret < 0)
		return -1;

	//建立信号函数，对子进程结束产生的SIG_CHLD信号捕捉并进行处理（wait收尸）
	signal(SIG_CHLD, SIG_IGN); 

	//对监听到的socket接受，进行数据传输
	for( ; ; ) {
		connfd = accept(listenfd, cli_addr, cli_socklen);
		if (connfd < 0) {
			if (errno == EINTR)
				continue;
		}
		else
			return -1;
	}
	return connfd;
}


