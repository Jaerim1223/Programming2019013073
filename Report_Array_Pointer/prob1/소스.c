#include <stdio.h>
#include <string.h>		
#define PWD	"abc123"	// 암호

int strcmp_password(char s[])
{
	if (strcmp(s, PWD) == 0)  
		return 1;    
	else
		return 0;   
}

int main()
{
	char s[20];   

	while (1)   
	{
		printf("암호를 입력하세요: ");
		gets(s);      // 키보드로 문자열 입력 받음
		if (strcmp_password(s) == 1)  
		{
			printf("normal termination..\n");
			break;               
		}
		printf("not matched, retry..\n");   
	}

	return 0;
}
