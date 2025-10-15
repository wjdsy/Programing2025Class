#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <stdio.h>

int main(void)
{
	char name[50];
	int student_id;
	float height, weight, bmi;

	printf("이름, 학번, 키(m), 몸무게(kg)를 입력하세요: ");
	scanf("%s %d %f %f", name, &student_id, &height, &weight);

	height = height / 100;
	bmi = weight / (height * height);

	printf("\n[입력 정보]\n");
	printf("이름: %s\n", name);
	printf("학번: %d\n", student_id);
	printf("키: %.2f m\n", height);
	printf("몸무게: %.2f kg\n", weight);

	printf("[BMI 결과]\n");
	printf("BMI: %.2f\n", bmi);

	return 0;
}