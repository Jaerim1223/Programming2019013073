#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 
#define N	100	// 데이터 개수
// 평균 구하기
// 평균 = 전체 합 / 개수
double average(int arr[], int size)
{
	int i;
	double sum = 0;
	for (i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
}

// 분산
double variance(int arr[], int size)
{
	double v, avg = 0, sum = 0;
	int i;

	avg = average(arr, size);

	for (i = 0; i < size; i++)

		sum += pow((arr[i] - avg), 2);
	v = sum / (size - 1);
	return v;
}

// 표준편차
double standard_deviation(int arr[], int size)
{
	double v = variance(arr, size);
	return sqrt(v);
}

void input_data(int arr[], int size)
{
	int i;
	srand((unsigned)time(NULL));

	for (i = 0; i < size; i++)
		arr[i] = rand() % 101;

}

void print_array(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[N];

	input_data(arr, N);
	print_array(arr, N);
	printf("\n평균 : %f\n", average(arr, N));
	printf("분산 : %f\n", variance(arr, N));
	printf("표준편차 : %f\n", standard_deviation(arr, N));
}