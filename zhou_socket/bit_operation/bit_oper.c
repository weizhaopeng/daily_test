#include "bit_oper.h"

int main(int argc, char **argv)
{
	/*create the space all types*/
	void *buf = NULL, *buf1 = NULL;

	buf = malloc(sizeof(int)*10);
	buf1 = malloc(sizeof(int)*12);

	/*test the bzero, 改变了字符缓冲的字节为0*/
	char *word = (char*)buf;
	scanf("%s", word);
	printf("%s\n", word);
	bzero(word, 3);
	printf("%s\n", word);

	uint32_t *num = NULL;
	num    = (uint32_t *)malloc(sizeof(uint32_t));
	num[0] = 0xA2;
	num[1] = 0xa5;
	num[3] = 0xA4;

	printf("%ld\n", *num);
	bzero(num, 2);
	printf("%ld\n", *num);
	//总是就是bzero是令内存中的一段存储区域的n个字节清零

	char *word1 = (char *)buf1;
	bcopy(word, buf1, sizeof(word));
	printf("%s\n", buf1);
	


	if (buf  != NULL)
		free(buf);
	if (buf1 != NULL)
		free(buf1);
	return 0;
}
