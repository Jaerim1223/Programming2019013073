#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void)
{
	char str[80];
	char str1[80];
	char* star = "**********";
	int a;

	printf("단어입력 : ");
	scanf_s("%s", str);
	a = strlen(str);

	if (a <= 5)
	{
		strcpy_s(str1, str);
	}
	else
	{
		strncpy(str1, str, 5);
		str1[5] = '\0';
		strncat_s(str1, star, a - 5);
	}

	printf("입력한 단어 : %s, 생략된 단어 : %s\n", str, str1);


	return 0;
}