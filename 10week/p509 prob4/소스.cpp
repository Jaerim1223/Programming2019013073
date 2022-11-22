#include <stdio.h>
#include <stdlib.h>


struct marriage
{
	char name[20];
	int age;
	char sex;
	double height;
};

int main(void)
{

	struct marriage m1 = { "Andy", 22, 'm', 187.5 };
	struct marriage* mp = &m1;

	printf("name : %s", mp->name);
	printf("age : %d", mp->age);
	printf("sex : %c", mp->sex);
	printf("height : % .1lf", mp->height);

	return 0;
}