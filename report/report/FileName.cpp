#include <stdio.h>

int main() {
    int a, b;

    
    printf("두 개의 정수를 입력하세요: ");
    scanf_s("%d %d", &a, &b);

   
    a++;
    --b;

    
    printf("\n[관계 연산 결과]\n");
    if (a > b)
        printf("a(%d)는 b(%d)보다 큽니다.\n", a, b);
    else if (a < b)
        printf("a(%d)는 b(%d)보다 작습니다.\n", a, b);
    else
        printf("a와 b는 같습니다.\n");

   
    printf("\n[논리 연산 결과]\n");
    if (a > 0 && b > 0)
        printf("a와 b 모두 양수입니다.\n");
    if (a < 0 || b < 0)
        printf("a 또는 b 중 하나는 음수입니다.\n");
    if (!(a == b))
        printf("a와 b는 서로 다릅니다.\n");

   
    printf("\n증감 연산 이후의 값: a = %d, b = %d\n", a, b);

    return 0;
}