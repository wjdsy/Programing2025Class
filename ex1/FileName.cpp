#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	// 1: 변수 선언
	char name[20];
	int student_id;
	double height;
	double weight;
	double simple_bmi;

	
	printf("이름, 학번, 키(cm), 몸무게(kg)를 순서대로 한 줄에 입력하세요: \n");


	scanf("%s %d %lf %lf", name, &student_id, &height, &weight);

	double height_m = height / 100.0;

	simple_bmi = weight / (height_m * height_m);
	
	simple_bmi = height * weight;

	
	printf("\n--- 입력 정보 확인 ---\n");
	printf("이름: %s\n", name);
	printf("학번: %d\n", student_id);
	printf("키: %.1lf cm\n", height);
	printf("몸무게: %.1lf kg\n", weight);


	printf("\n--- 간단 BMI 유사 계산 결과 ---\n");
	printf("키 * 몸무게 값 (간단 BMI): %.2lf\n", simple_bmi);

	return 0;
}