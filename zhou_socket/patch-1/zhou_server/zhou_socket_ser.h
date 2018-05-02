#ifndef _ZHOU_SOCKET_SER_H_
#define _ZHOU_SOCKET_SER_H_

typedef struct addrpair {
	struct sockaddr_in *seraddr;
	socklen_t 		   *seraddr_len;
	struct sockaddr_in *cliaddr;
	socklen_t		   *cliaddr_len;
}addrpair;

//功能函数
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//socket相关函数和sockaddr地址
#include <sys/socket.h>
#include <sys/types.h>
//sockaddr_in头文件
#include <netinet/in.h>
//read函数头文件
#include <unistd.h>
//inet_pton函数头文件
#include <arpa/inet.h>
//bzero函数头文件
#include <strings.h>
//信号函数头文件
#include <signal.h>
//select函数头文件
#include <sys/select.h>


//tcp connect 
int zhou_socket_ser(addrpair *ap);

#endif
