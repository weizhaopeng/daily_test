#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main (void)
{
	int 	 a;
	char 	 b;
	char 	 c[10], *buf = NULL;
	double   d;
	uint32_t f;
	uint16_t g;
	size_t   h;

	buf = malloc(sizeof(char)*10);

	/*TODO:用*省略读取缓冲区中的内容
	scanf("%*d%s%lf", c, &d);
	printf("%s%lf", c, d);
	*/
	/*
	sscanf("nihao 3345", "%s%d", c, &f);
	printf("%s%d", c, f);
	*/

	/*TODO:用%5s读取缓冲区指定长度的字符串，只能是字符串
	sscanf("nihaowojiao", "%5s", buf);
	printf("%s", buf);
	*/
	
	/*TODO:%[^x]s,只能用于读取字符串，并且读取到出现
	 x字符或者[]中的范围字符的时候，不再读取后面的内容，包括后面的项目
	sscanf("nihaowo jiushi2345", "%s%[^1-4]s", c, buf);
	sscanf("nihaowo jiushi2345", "%s%[^4]s"  , c, buf);
	printf("%s%s\n", c, buf);
	 */

	/*TODO:读取字符读取位于a-z 1-9的字符
	sscanf("nihao1wo3he$:n4aini5", "%[a-z1-9]s", buf);
	printf("%s\n", buf);
	 */

	
	if (buf)
		free(buf);
	return 0;
	
}


