#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <stdio.h>

int main(void)
{
	char name[50];
	int student_id;
	float height, weight, bmi;

	printf("�̸�, �й�, Ű(m), ������(kg)�� �Է��ϼ���: ");
	scanf("%s %d %f %f", name, &student_id, &height, &weight);

	height = height / 100;
	bmi = weight / (height * height);

	printf("\n[�Է� ����]\n");
	printf("�̸�: %s\n", name);
	printf("�й�: %d\n", student_id);
	printf("Ű: %.2f m\n", height);
	printf("������: %.2f kg\n", weight);

	printf("[BMI ���]\n");
	printf("BMI: %.2f\n", bmi);

	return 0;
}