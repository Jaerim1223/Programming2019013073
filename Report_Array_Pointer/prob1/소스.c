#include <stdio.h>
#include <string.h>		
#define PWD	"abc123"	// ��ȣ

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
		printf("��ȣ�� �Է��ϼ���: ");
		gets(s);      // Ű����� ���ڿ� �Է� ����
		if (strcmp_password(s) == 1)  
		{
			printf("normal termination..\n");
			break;               
		}
		printf("not matched, retry..\n");   
	}

	return 0;
}
