#include <stdio.h>

int main(void) {
    int num1, num2, a, b, temp, g, l;

    printf("두 숫자를 입력하세요 (while 버전): ");
    scanf_s("%d %d", &num1, &num2);

    a = num1;
    b = num2;
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    g = a; 

    if (g == 0) {
        l = 0;
    }
    else {
        l = (num1 * num2) / g; 

        if (l < 0) l = -l;
    }

    printf("GCD: %d, LCM: %d\n", g, l);
    return 0;
}