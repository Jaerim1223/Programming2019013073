#include <stdio.h>

// ���� �ѹ��� ����� ����
#define X 0
#define Y 1
#define Z 2
#define A 3

// �迭, �׸��� ���(A) �Ǵ� ������(unknown)�� �Է¹޾�, ũ���� ������ �̿��Ͽ� ���� �ظ� ����
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

    // ����ڰ� ���ϴ� ���� �Է��ϸ� ũ���� �������� Ǯ �� �ִ� �߰����
    printf("�� ���α׷��� �������� 3���� ���������������� ũ���� �������� Ǯ���մϴ�.\n\n");
    printf("x + y - z = 0\n2x - y + 3z = 9\nx + 2y + z = 8\n");
    printf("\n�ٸ� ���� ũ���� �������� Ǯ�� �ʹٸ� n, �׷��� ������ �ƹ� ���ڳ� �Է����ּ���.\n> ");
    scanf_s(" %c", &sign);
    if (sign == 'n') {
        printf("\nǮ�� ���� �Ŀ��� �������� ����� ������� �Է����ּ���.\n\n");
        printf("�Է� ����:\n");
        printf("x + y - z = 0\n2x - y + 3z = 9\nx + 2y + z = 8�� ���\n");
        printf("\n1 1 -1 2 -1 3 1 2 1\n\n> ");
        for (int i = 0; i < 9; i++) {
            scanf_s(" %d", &a[i / 3][i % 3]);
        }
        printf("\n������� ���� ������� �Է����ּ���.\n\n");
        printf("�Է� ����:\n");
        printf("x + y - z = 0\n2x - y + 3z = 9\nx + 2y + z = 8�� ���\n");
        printf("\n0 9 8\n\n> ");
        for (int i = 0; i < 3; i++) {
            scanf_s(" %d", &b[i]);
        }
    }

    determinant[0] = cramer(a, b, X); // |X| ���ϱ�
    determinant[1] = cramer(a, b, Y); // |Y| ���ϱ�
    determinant[2] = cramer(a, b, Z); // |Z| ���ϱ�
    determinant[3] = cramer(a, b, A); // |A| ���ϱ�

    printf("\nx, y, z: ");
    for (int i = 0; i < 3; i++)
        printf("%f ", (double)determinant[i] / (double)determinant[3]);
    printf("\n");
    return (0);
}