#ifndef _ZHOU_SOCKET_CLI_H_
#define _ZHOU_SOCKET_CLI_H_

#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <stdint.h>
#include <unistd.h>

#define SIN_PORT 5535
/*
 *进行tcp连接
 */
int zhou_socket_cli(const char *server_ip, const uint16_t port);
int zhou_socket_free(int connfd);
#endif
