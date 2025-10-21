#include <stdio.h>

int main() {
    int chest;
    char size;

   
    printf("가슴둘레를 입력하세요 (cm): ");
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

    // 결과 출력
    printf("가슴둘레: %dcm => 사이즈: %c\n", chest, size);

    return 0;
}