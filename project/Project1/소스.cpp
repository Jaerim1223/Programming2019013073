#include <stdio.h>

// 매직 넘버를 상수로 선언
#define X 0
#define Y 1
#define Z 2
#define A 3

// 배열, 그리고 계수(A) 또는 미지수(unknown)를 입력받아, 크래머 공식을 이용하여 구한 해를 리턴
int cramer(int a[3][3], int b[3], int unknown) {
    int result = 0;
    int temp[3][3];

    for (int i = 0; i < 9; i++) {
        temp[i / 3][i % 3] = a[i / 3][i % 3];
        if (i % 3 == unknown) temp[i / 3][i % 3] = b[i / 3];
    }

    for (int i = 0; i < 3; i++) {
        result += temp[i][0] * temp[(i + 1) % 3][1] * temp[(i + 2) % 3][2];
        result -= temp[i][2] * temp[(i + 1) % 3][1] * temp[(i + 2) % 3][0];
    }

    return (result);
}

int main(void) {
    char sign;
    int a[3][3] = { {1, 1, -1}, {2, -1, 3}, {1, 2, 1} };
    int b[3] = { 0, 9, 8 };
    int determinant[4];

    // 사용자가 원하는 식을 입력하면 크래머 공식으로 풀 수 있는 추가기능
    printf("이 프로그램은 미지수가 3개인 연립일차방정식을 크래머 공식으로 풀이합니다.\n\n");
    printf("x + y - z = 0\n2x - y + 3z = 9\nx + 2y + z = 8\n");
    printf("\n다른 식을 크래머 공식으로 풀고 싶다면 n, 그렇지 않으면 아무 문자나 입력해주세요.\n> ");
    scanf_s(" %c", &sign);
    if (sign == 'n') {
        printf("\n풀고 싶은 식에서 미지수의 계수를 순서대로 입력해주세요.\n\n");
        printf("입력 예시:\n");
        printf("x + y - z = 0\n2x - y + 3z = 9\nx + 2y + z = 8의 경우\n");
        printf("\n1 1 -1 2 -1 3 1 2 1\n\n> ");
        for (int i = 0; i < 9; i++) {
            scanf_s(" %d", &a[i / 3][i % 3]);
        }
        printf("\n상수항의 값을 순서대로 입력해주세요.\n\n");
        printf("입력 예시:\n");
        printf("x + y - z = 0\n2x - y + 3z = 9\nx + 2y + z = 8의 경우\n");
        printf("\n0 9 8\n\n> ");
        for (int i = 0; i < 3; i++) {
            scanf_s(" %d", &b[i]);
        }
    }

    determinant[0] = cramer(a, b, X); // |X| 구하기
    determinant[1] = cramer(a, b, Y); // |Y| 구하기
    determinant[2] = cramer(a, b, Z); // |Z| 구하기
    determinant[3] = cramer(a, b, A); // |A| 구하기

    printf("\nx, y, z: ");
    for (int i = 0; i < 3; i++)
        printf("%f ", (double)determinant[i] / (double)determinant[3]);
    printf("\n");
    return (0);
}