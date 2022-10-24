#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 
#define N	100	

int main()
{
	double arr_h[N];
	double arr_v[N];
	int err_target = 0;

	int i;
	srand((unsigned)time(NULL));


	for (i = 0; i < N; i++)
	{

		arr_h[i] = rand() % 31 / 10.0;
		arr_v[i] = rand() % 33 / 10.0;
	}

	printf("[실험발사 %d회 탄착점]\n", N);
	for (i = 0; i < N; i++)
		printf("(%.1f,%.1f) ", arr_h[i], arr_v[i]);
	printf("\n");

	// 실패 횟수 계산
	for (i = 0; i < N; i++)
	{
		if (arr_h[i] > 2.0 ||
			arr_v[i] > 2.0)
			err_target++;

	}


	printf("\n발사 횟수: %d\n", N);
	printf("명중 횟수: %d\n", N - err_target); // 명중횟수 = 총횟수 – 실패횟수
	printf("실패 횟수: %d\n", err_target);

	printf("명중률   : %.2f%%\n\n", (double)(N - err_target) / N * 100);
}