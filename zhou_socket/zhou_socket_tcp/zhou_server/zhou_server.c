#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	//定义本地socket
	int listenfd;

	listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenfd < 0) {
		perror("server listen socket create");
		return -1;
	}

	//创建当前服务器socket和客户端的存储地址端口结构
	struct sockaddr_in serv_addr;
	socklen_t		   serv_socklen = sizeof(struct sockaddr_in);
	
	bzero(&serv_addr, len);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port	 = htons(SOCKPROT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	//将服务器地址端口绑定到listenfd上
	int ret;
	
	ret = bind(listenfd, (struct sockaddr*)&serv_addr, serv_socklen);
	if (ret < 0) {
		perror("bind");
		return -1;
	}

	//对绑定的socket进行监听
	ret = listen(listenfd, 10);
	if (ret < 0) {
		perror("listen");
		return -1;
	}

	//建立信号函数，对子进程结束产生的SIG_CHLD信号捕捉并进行处理（wait收尸）
	signal(SIG_CHLD, child_hander);

	//对监听到的socket接受，进行数据传输
	int 	  connfd;
	struct    sockaddr_in cli_addr;
	socklen_t cli_socklen = sizeof(cli_addr);
	pid_t	  chat_pid;

	for( ; ; ) {
		connfd = accept(listenfd, &cli_addr, &cli_socklen);
		if (connfd < 0) {
			if (errno == EINTR)
			continue;
		}
		else {
			perror("accept");
			return -1;
		}

		chat_pid = fork();
		if (chat_pid == 0) {
			//TODO 执行的函数或者程序操作
			ret = execvpe("chat_server", child_argv, envp);
			if (ret < 0) {
				perror("child process");
				return -1;
			}
			close(listenfd);
		}
		close(connfd);
	}
	return 0;
}


