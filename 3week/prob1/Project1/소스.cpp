#include <stdio.h>

int main(void)
{
	int age, chestsize;
	char size;
	printf("Input your age:");
	scanf_s("%d", &age);

	printf("Input your chestsize:");
	scanf_s("%d", &chestsize);

	if (age < 20)
	{
		if (chestsize < 85) size = 'S';
		else if ((chestsize >= 85 )&&(chestsize < 95)) size = 'M';
		else size = 'L';
	}
	else
	{
		if (chestsize < 90) size = 'S';
		else if ((chestsize >= 90) && (chestsize < 100)) size = 'M';
		else size = 'L';
	}
	printf("your size is %c \n", size);
	return 0;
}