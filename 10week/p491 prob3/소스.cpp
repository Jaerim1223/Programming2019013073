#include <stdio.h>
#include <stdlib.h>

struct cracker
{
	int price;
	int calories;
};

int main(void)
{
	struct cracker basasak;
	printf("Enter the price and calories of the basasak : ");
	scanf_s("%d%d", &basasak.price, &basasak.calories);
	printf("The price of basasak : %dwon\n", basasak.price);
	printf("The calories of basasak : %dkcal\n", basasak.calories);

	return 0;
}