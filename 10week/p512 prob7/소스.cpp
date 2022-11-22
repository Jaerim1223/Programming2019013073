#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct

{
	int num;                  // 학번
	char name[20];            // 이름
	int kor, eng, mat;        // 3과목 점수
	int tot;                  // 총점
	double avg;               // 평균
	char grade;               // 학점
} Student;

void input(Student* pary);
void calc(Student* pary);
void sort(Student* pary);
void print(Student* pary);

int main(void)
{
	Student ary[5];           // 5명 학생의 성적
	input(ary);          // 학번, 이름, 3과목 점수 입력
	calc(ary);           // 총점, 평균, 학점 계산

	printf("# 정렬 전 데이터 : \n");
	print(ary);          // 정렬 전 출력
	sort(ary);           // 총점 순으로 내림차순 정렬
	printf("# 정렬 후 데이터 : \n");
	print(ary);          // 정렬 후 출력

	return 0;
}
