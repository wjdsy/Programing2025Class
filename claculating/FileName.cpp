#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("사칙연산 입력(정수): ");
    scanf("%d%c%d", &a, &op, &b);

    if (op == '+') {
        printf("%d%c%d=%d\n", a, op, b, a + b);
    }
    else if (op == '-') {
        printf("%d%c%d=%d\n", a, op, b, a - b);
    }
    else if (op == '*') {
        printf("%d%c%d=%d\n", a, op, b, a * b);
    }
    else if (op == '/') {
        if (b == 0) {
            printf("0으로 나눌 수 없습니다!\n");
        }
        else {
            printf("%d%c%d=%d\n", a, op, b, a / b);
        }
    }
    else {
        printf("지원하지 않는 연산자입니다!\n");
    }

    return 0;
}