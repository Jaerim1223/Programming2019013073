#include <stdio.h>
#define MAX_PATH 256


void reName(char* input, char* newName)
{

	int result = rename(input, newName);
	if (result != 0)
		printf("Could not rename '%s'\n", input);
	else
		printf("File '%s' renamed to '%s'\n", input, newName);
}

int main() {
	char input[MAX_PATH];
	char newName[MAX_PATH];

	printf_s("input old_name : ");
	scanf_s("%s", &input, sizeof(input));
	printf_s("input new_name : ");
	scanf_s("%s", &newName, sizeof(newName));

	reName(input, newName);
}