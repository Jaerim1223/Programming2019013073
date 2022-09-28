#include <stdio.h>

#define MINCHESTSIZE 90
#define MAXCHESTSIZE 100


int main(void)
{
	int nchestsize = 0;
	char chestsize;

	printf("Input your chest size:\n");
	scanf_s("%d", &nchestsize);

	if (nchestsize <= MINCHESTSIZE)
	{
		chestsize = 'S';
		printf("\nS\n");
	}
	else if ((nchestsize < MINCHESTSIZE) && (nchestsize <= MAXCHESTSIZE))
	{
		chestsize = 'M';
		printf("\nM\n");
	}
	else
	{
		chestsize = 'L';
		printf("\nL\n");
	}
	
	return 0;
}