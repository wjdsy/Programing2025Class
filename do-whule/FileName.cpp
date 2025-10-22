#include <stdio.h>

int main(void) {
    int num1, num2;
    int a, b;
    int temp;
    int g;
    int l;

    printf("두 숫자를 입력하세요: ");

   
    if (scanf_s("%d %d", &num1, &num2) != 2) {
        return 0;
    }

    int abs_num1 = (num1 < 0) ? -num1 : num1;
    int abs_num2 = (num2 < 0) ? -num2 : num2;

    a = abs_num1;
    b = abs_num2;

    if (a == 0 && b == 0) {
        g = 0;
        l = 0;
    }
    else {
       
        if (b != 0) {
            do {
                temp = a % b;
                a = b;
                b = temp;
            } while (b != 0);
        }
        
        g = a; 

        l = (abs_num1 / g) * abs_num2;
    }

    printf("GCD: %d, LCM: %d\n", g, l);
    return 0;
}