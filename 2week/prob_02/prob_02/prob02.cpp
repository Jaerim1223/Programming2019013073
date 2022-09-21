#include <stdio.h>
int main(void)
{
	char ch;
	printf("input your word : ");
	scanf_s("%c", &ch);
	printf("입력한 문자의 아스키 코드 값은 %d.\n", ch);
	return 0;
}
