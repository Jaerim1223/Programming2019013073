#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int rec_func(int n);

int main(void)
{
	printf("Total : %d\n", rec_func(10));

	return 0;
}

int rec_func(int n)
{
	if (n == 1)
		return 1;

	return n + rec_func(n - 1);
}