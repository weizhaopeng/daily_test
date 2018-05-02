#include "zhou_chat_ser.h"

int zhou_chat_ser(int connfd1, int connfd2, void *connfdset)
{
	//定义了select的参数：maxfdp1， 读写描述符集，读写缓冲区
	int maxfdp1;
	fd_set rset, wset;
	char read_buf[BUFSIZE], write_buf[BUFSIZE]; 

	//利用FD_ZERO宏将读写描述符集全部置零
	FD_BZERO(&rset);
	FD_BZERO(&wset);

	for ( ; ; ) {
		//将文件描述符定义到文件描述符集的对应位
		FD_SET(connfd, &rset);
		
		//定义maxfdp1的值
		maxfdp1 = connfd+1;

		//针对读写进行select，不包括错误，永久拥塞
		ret = select(maxfdp1, &rset, &wset, NULL, NULL);
		if (ret < 0)
			return -1;

		//根据rset和wset判断是否可以读写，可以读写对应为置1
		if (FD_ISSET(connfd, &rset)) {
			if (read(connfd, read_buf, BUFSIZE) <= 0)
				return -1;
			else {
				//TODO 使用多线程通信，将读到的内容传递给另一个进程
			}

			if (FD_ISSET(connfd, &wset)) {
				if (write(connfd, write_buf, BUFSIZE) == 0)
					return -1;
			}
		}
	}
	return 0;
}

