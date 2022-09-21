#include <stdio.h>
int main(void)
{
	double height, weight, bmi;
	printf("enter your weight and height:");
	scanf_s("%lf%lf", &weight, &height);
	height = height / 100;
	bmi = weight / (height * 2);
	printf("%s$n", ((bmi >= 20.0) && (bmi < 25.0)) ? "It's the standard" : "you need to take care of my weight.");

	return 0;
}
