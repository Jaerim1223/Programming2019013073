#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996) //c4996에러 무시

int main(void)
{
	char str[80];
	strcpy_s(str, 80, "wine");
	strcat_s(str, 80, "apple");
	strncpy(str, "pine", 1);
	printf("%s, %d\n", str, strlen(str));



	//printf("%s, %d\n", str, (int)strlen(str));

	return 0;
}