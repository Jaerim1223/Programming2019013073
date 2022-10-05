#include<stdio.h>

int main(void)
{
	int n;
	int i = 1;
	
	printf("Enter a number from 2 to 9 :");
	scanf_s("%d", &n);

	while (i <= 9)
	{
		printf("%d * %d = %d\n", n, i, n * i);
		i++;
	}
	return 0;
}