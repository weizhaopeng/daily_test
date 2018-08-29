#include <stdio.h>
#include <strings.h>
#include <string.h>

typedef struct buffer{
    char ch;
    int is_zero;
} buffer;

int main(int argc, char *argv[]) {
	buffer buf[54];
    char   str[100];
    int    posi;
				    
    bzero(buf, 54*sizeof(buffer));
    scanf("%s", str);
    for (int i = 0; i < strlen(str)-1; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
        	posi = (int)str[i]-'a' + 26;
        else { 
            if (str[i] >= 'A' && str[i] <= 'Z')
	 	       posi = (int)str[i]-'A';
   	        else
		        continue;
		}
		buf[posi].ch = str[i];
        buf[posi].is_zero = -1; 
	}
	for (int i = 0;i < 54 ; i++) {
       if (buf[i].is_zero == -1)
	       printf("%c", buf[i].ch);
	}
	return 0;
}
