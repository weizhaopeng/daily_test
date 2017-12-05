#include"test.h"

void main (void)
{
	FILE *fp;
	char ch[100],ch1;
	
	if((fp=fopen("file","a+"))==NULL)
	{
		puts("open error");
	}
	int i;
	for( i=0;i<10&&ch[i]!=EOF;i++)
	fread(ch+i,sizeof(char),1,fp);
	ch[i]='\0';
	printf("%s",ch);

	fclose(fp);
}

	
