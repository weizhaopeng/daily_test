#include <stdio.h>
#include <errno.h>

int main (int argc, char **argv)
{
	extern int errno;
	FILE *fp;

	fp = fopen("file_error", "r");
	perror("error:");
	return 0;
}
