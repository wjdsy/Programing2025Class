#include <stdio.h>

int main() {
    int chest;
    char size;

   
    printf("�����ѷ��� �Է��ϼ��� (cm): ");
    scanf_s("%d", &chest);

   
    if (chest <= 90) {
        size = 'S';
    }
    else if (chest <= 100) {
        size = 'M';
    }
    else {
        size = 'L';
    }

    // ��� ���
    printf("�����ѷ�: %dcm => ������: %c\n", chest, size);

    return 0;
}