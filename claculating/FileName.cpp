#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("��Ģ���� �Է�(����): ");
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
            printf("0���� ���� �� �����ϴ�!\n");
        }
        else {
            printf("%d%c%d=%d\n", a, op, b, a / b);
        }
    }
    else {
        printf("�������� �ʴ� �������Դϴ�!\n");
    }

    return 0;
}