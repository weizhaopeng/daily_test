#include "zhou_socket_ser.h"

int zhou_socket_ser(addrpair *ap)
{
	//定义本地socket
	int listenfd;
	int connfd;

	listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenfd < 0)
		return -1;

	//将服务器地址端口绑定到listenfd上
	int ret;
	
	ret = bind(listenfd, (struct sockaddr*)ap->seraddr, *ap->seraddr_len);
	if (ret < 0)
		return -1;

	//对绑定的socket进行监听,backlog是未连接和已连接的队列总数
	ret = listen(listenfd, 10);
	if (ret < 0)
		return -1;

	//建立信号函数，对子进程结束产生的SIG_CHLD信号捕捉并进行处理（wait收尸）
	signal(SIG_CHLD, SIG_IGN); 

	//对监听到的socket接受，进行数据传输
	for( ; ; ) {
		connfd = accept(listenfd,ap->cliaddr,ap->cliaddr_len);
		if (connfd < 0) {
			if (errno == EINTR)
				continue;
		}
		else
			return -1;
	}
	return connfd;
}
	
