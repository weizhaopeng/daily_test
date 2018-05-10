#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <sys/select.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
	
#define max(a, b) (a > b?a : b)
int main(int argc, char *argv[]) {
	//TODO init variates
	int   fd[2];
	pid_t pid1, pid2;
	
	socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
	pid1 = fork();
	pid2 = fork();

	//TODO cp1 send
	if (pid1 == 0) {
		char 			buf1[100];
		int  			ret, maxfd1 = max(STDIN_FILENO, fd[1])+1;
		fd_set 		   *rset, *wset;
		struct timeval *timeout = {tv_sec:10, tv_usec:20};

		FD_SET(fd[1], rset);
		FD_SET(fd[1], write);
		FD_SET(STDIN_FILENO, rset);
		close(fd[0]);

		while (1) {
			bzero(buf, 100);
			fflush(stdout);
			fflush(stdin);

			ret = select(maxfd1, rset, wset, 0, timeout);
			if (ret > 1) {
				if (FD_ISSET(STDIN_FILENO, rset) && FD_ISSET(fd[1], wset)) {
					read(fileno(stdin), buf, 100);
					write(fd[1], buf, 100);
				}
				if (FD_ISSET(fd[1], rset)) {
					read(fd[1], buf, 100);
					write(STDOUT_FILENO, buf, 100);
				}
			}
			if (ret == -1 && errno == EINTR)
				continue;
		}
	}

	//TODO cp2 process
	if (pid2 == 0) {
		struct pollfd fds[2]
		char   		  buf2[100], buf3[50] = "from cp2";
		int 		  ret, nfds = 2, timeut = 20;
	
		fds[0].fd 	 = fd[0];
		fds[0].event = POLLIN;
		fds[1].fd    = fd[0];
		fds[1].event = POLLOUT;

		close(fd[1]);
		while(1) {
			ret = poll(fd, nfds, timeout);
			if (ret > 0) {
				if (fds[0].revent == POLLIN) {
					if (read(fd[0], buf2, 50) > 0)
						strncat(buf2, buf3, 50);
					else
						exit(0);
				}
				if (fds[1],revent == POLLOUT)
					write(fd[0], buf2, 100);
			}
			if (ret == -1 && errno == EINTR)
				continue;
			else 
				exit(-1);
		}
	}

	//TODO cp1 receive and print
	waitpid(pid1, 0, 0);
	wiatpid(pid2, 0, 0);
	return 0;
}


/*
int main(int argc, char *argv[]) {
	int   fd[2], ret;
	pid_t pid1, pid2;
	ret = socketpair(AF_UNIX, SOCK_STREAM, 0, fd);

	pid1 = fork();
	pid2 = fork();
	
	if (pid1 == 0) {
		char buf[100];

		while (1) {
			bzero(buf, 100);
			close(fd[1]);
			if (read(fd[1], buf, 100) > 0) {
				fflush(stdout);
				write(STDOUT_FILENO, buf, 100);
				continue;
			}
		}
	}

	if (pid2 == 0) {
		char buf[100];
		while (1) {
			bzero(buf, 100);
			close(fd[0]);
			fflush(stdin);
			if (read(STDIN_FILENO, buf, 100) > 0) {
				write(fd[0], buf, 100);
				continue;
			}
		}
	}

	return 0;
}
*/

