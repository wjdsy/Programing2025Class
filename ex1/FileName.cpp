#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	// 1: ���� ����
	char name[20];
	int student_id;
	double height;
	double weight;
	double simple_bmi;

	
	printf("�̸�, �й�, Ű(cm), ������(kg)�� ������� �� �ٿ� �Է��ϼ���: \n");


	scanf("%s %d %lf %lf", name, &student_id, &height, &weight);

	double height_m = height / 100.0;

	simple_bmi = weight / (height_m * height_m);
	
	simple_bmi = height * weight;

	
	printf("\n--- �Է� ���� Ȯ�� ---\n");
	printf("�̸�: %s\n", name);
	printf("�й�: %d\n", student_id);
	printf("Ű: %.1lf cm\n", height);
	printf("������: %.1lf kg\n", weight);


	printf("\n--- ���� BMI ���� ��� ��� ---\n");
	printf("Ű * ������ �� (���� BMI): %.2lf\n", simple_bmi);

	return 0;
}