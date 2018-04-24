#include "zhou_socket_tcp.h"

#define max(a, b) (a > b?a:b)

int chat_client(int connfd) {
	int maxfdp1;
	fd_set rset, wset;
	char rbuf[MAXSIZE], wbuf[MAXSIZE];
	int _stdin = stdno(stdin);

	FD_ZERO(&rset);
	FD_ZERO(&wset);
	maxfdp1 = max(connfd, _stdin)+1;

	select(maxfdp1, &rset, &wset, NULL,NULL);
	for ( ; ; ) {
		if (read(connfd, wbuf, MAXSIZE) < 0) {
			if (errno == EINTR)
				continue;
			return 0;
		}
		else {
			if (write(stdout, wbuf, MAXSIZE) < 0) {
				perror("output");
				continue;
			}

		if (read(stdin, rbuf, MAXSIZE) < 0)
			continue;
	}
	return 0;
}

			
