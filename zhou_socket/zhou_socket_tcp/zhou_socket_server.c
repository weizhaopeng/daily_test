#include "zhou_socket_tcp.h"

int main(int argc, char **argv)
{
	int sock_fd;

	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0) {
		perror("error");
		return -1;
	}


