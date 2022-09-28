#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Sum '+'
#define Min '-'
#define Mul '*'
#define Inv '/'
#define Re '%'

int main(void)
{
	int a = 0;
	int b = 0;
	int res = 0;
	char Cal;
	printf("Calculation : ");
	scanf_s("%d%c%d", &a, &Cal, 1, &b);

	switch (Cal)
	{
	case Sum:
		res = a + b;
		printf("%d%c%d = %d\n", a, Cal, b, res);
		break;
	case Min:
		res = a - b;
		printf("%d%c%d = %d\n", a, Cal, b, res);
		break;
	case Mul:
		res = a * b;
		printf("%d%c%d = %d\n", a, Cal, b, res);
	case Inv:
		res = a / b;
		printf("%d%c%d = %d", a, Cal, b, res);
		break;
	
	default:
		printf("Entered it incorrectly!!");
	}

	return 0;
}