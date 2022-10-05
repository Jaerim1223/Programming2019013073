#include<stdio.h>

int main(void)
{
	int a, b;
	int result;
	int n;

	printf("Please enter the first number : ");
	scanf_s("%d", &a);
	printf("<1> Sum, <2> Min, <3> Mul, <4> Inv \nPlease enter your number: ");
	scanf_s("%d", &n);
	printf("Please enter the second number: ");
	scanf_s("%d", &b);

	while (1)
	{
		if (n == 1) {
			result = a + b;
			printf("%d + %d = %d", a, b, result);
		}
		if (n == 2) {
			result = a - b;
			printf("%d - %d = %d", a, b, result);
		}
		if (n == 3) {
			result = a * b;
			printf("%d * %d = %d", a, b, result);
		}
		if (n == 4) {
			result = a / b;
			printf("%d / %d = %d", a, b, result);
		}

		return 0;
	}
}