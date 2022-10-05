#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a, b, c;
    int n;
    int cnt = 0;

    printf("enter an integer greater than 2: ");
    scanf_s("%d", &a);


    if (2 <= a)
    {
        for (b = 2; b < a; b++)
        {
            n = 1;
            for (c = 2; c < b; c++)
            {
                if (b % c == 0) 
                {
                    n = 0;
                    break;
                }
            }
            if (n == 1)
            {
                printf("%5d", b);
                cnt++;
                if (cnt % 5 == 0)
                {
                    printf("\n");
                }
            }
        }
    }
    else
    {
        printf("Error");
    }
    return 0;
}