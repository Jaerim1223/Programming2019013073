#include <stdio.h>
#include <stdlib.h>

struct address
{
	char title[30];
	char author[20];
	int page;
	int price;
};

int main(void)
{
	struct address list[3] = {
		{"The little prince", "Saint Tax Peri", 136, 11800},
		{"Harry Potter", "j.k,Rowling", 268, 9000},
		{"Swans and bats", "Higashono Kie", 568, 18000},
	};

	int i;

	for (i = 0; i < 3; i++)
	{
		printf("%15s%20s%10d%15d\n",
			list[i].title, list[i].author, list[i].page, list[i].price);
	}

	return 0;
}