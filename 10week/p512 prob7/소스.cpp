#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct

{
	int num;                  // �й�
	char name[20];            // �̸�
	int kor, eng, mat;        // 3���� ����
	int tot;                  // ����
	double avg;               // ���
	char grade;               // ����
} Student;

void input(Student* pary);
void calc(Student* pary);
void sort(Student* pary);
void print(Student* pary);

int main(void)
{
	Student ary[5];           // 5�� �л��� ����
	input(ary);          // �й�, �̸�, 3���� ���� �Է�
	calc(ary);           // ����, ���, ���� ���

	printf("# ���� �� ������ : \n");
	print(ary);          // ���� �� ���
	sort(ary);           // ���� ������ �������� ����
	printf("# ���� �� ������ : \n");
	print(ary);          // ���� �� ���

	return 0;
}
