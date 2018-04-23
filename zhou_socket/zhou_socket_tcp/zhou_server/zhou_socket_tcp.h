#ifndef _ZHOU_SOCKET_TCP_H_
#define _ZHOU_SOCKET_TCP_H_

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
#define SOCKPORT 	  19
#define SERVER_ADDR_P 120.79.130.38

/*
 *提供了连接tcp的通用的外部接口
 */
int zhou_tcp_server(struct sockaddr *cli_addr, socklen_t *cli_len, in_port_t *tcp_port);

int zhou_tcp_client(struct sockaddr *ser_addr, socklen_t *ser_len, in_port_t *ser_port);

#endif
