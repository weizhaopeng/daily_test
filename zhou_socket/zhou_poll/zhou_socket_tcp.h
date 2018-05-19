#ifndef _ZHOU_SOCKET_TCP_H_
#define _ZHOU_SOCKET_TCP_H_

//功能函数
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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
//poll函数头文件
#include <poll.h>

#define SOCKPORT 	  19
#define SERVER_ADDR_P 120.79.130.38

#endif
