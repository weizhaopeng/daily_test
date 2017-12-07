#include"test.h"

void main (void)
{
	FILE *fp;
	char ch[100],ch1[100];
	//打开文件
	if((fp=fopen("file","r"))==NULL)
	{
		puts("open error");
	}
	printf("%d\n",feof(fp));
	//写入文件
	printf("please input a string\n");
	scanf("%s",ch);
	fwrite(ch,sizeof(char),10,fp);
	clearerr(fp);
	if(ferror(fp)!=0)
	{
		puts("读写错误");
		exit(-1);
	}
	//读取文件内容
	rewind(fp);
	printf("%d\n",feof(fp));
	fread(ch1,sizeof(char),40,fp);
	if(ferror(fp)!=0)
	{
		puts("读写错误");
		exit(-1);
	}
	printf("%s\n",ch1);
	//返回位置
	fseek(fp,-4L,2);
	printf("%ld\n",ftell(fp));
	
		
	
	
	fclose(fp);
}

	
