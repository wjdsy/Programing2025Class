#include <stdio.h>

int main() {
    int age = 25, chest = 95;
    char size;

    printf("���̸� �Է��ϼ���: ");
    scanf_s("%d", &age);

    printf("�����ѷ��� �Է��ϼ��� (cm): ");
    scanf_s("%d", &chest);

    if (age < 20) { 
        if (chest <= 85) {
            size = 'S';
        }
        else if (chest <= 95) {
            size = 'M';
        }
        else {
            size = 'L';
        }
    }
    else {
        if (chest <= 90) {
            size = 'S';
        }
        else if (chest <= 100) {
            size = 'M';
        }
        else {
            size = 'L';
        }
    }

    printf("������� %c�Դϴ�.\n", size);

    return 0;
}