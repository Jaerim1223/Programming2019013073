#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 
#define n	3   
#define m	2

void print_array_a(int a[][m], int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
}
void print_array_b(int a[][n], int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[n][m];
	int b[m][n];
	int c[n][n] = { 0 };
	int i, j, k;

	srand((unsigned)time(NULL));


	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10;
			b[j][i] = rand() % 10;
		}


	printf("[행렬 A]\n");
	print_array_a(a, n, m);
	printf("\n[행렬 B]\n");
	print_array_b(b, m, n);



	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}


	printf("\n[행렬 A*B]\n");
	print_array_a(c, n, n);
}