#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 

void print_array(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

// f:0 - 오름차순 정렬
// f:1 - 내림차순 정렬
void sort(int arr[], int size, int f)
{
	int i, j, idx, temp;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (f == 0)
			{
				if (arr[j] < arr[idx]) idx = j;
			}
			else
			{
				if (arr[j] > arr[idx]) idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
}
int main()
{
	int i, a[10];

	srand((unsigned)time(NULL));


	for (i = 0; i < 10; i++)
		a[i] = rand() % 100;

	printf("[원본 데이터]\n");
	print_array(a, 10);

	sort(a, 10, 0);
	printf("\n[오름차순 정렬]\n");
	print_array(a, 10);

	sort(a, 10, 1);
	printf("\n[내림차순 정렬]\n");
	print_array(a, 10);

}