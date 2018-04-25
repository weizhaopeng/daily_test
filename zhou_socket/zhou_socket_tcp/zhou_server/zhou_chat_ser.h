#ifndef _ZHOU_CHAT_SER_H_
#define _ZHOU_CHAT_SER_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 0x60

int zhou_chat_ser(int connfd);

#endif
