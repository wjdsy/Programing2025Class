#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int people;
    double baggage;
    double total_weight;

    printf("탑승 인원 수를 입력하세요 (0~3명): ");
    scanf_s("%d", &people);
    printf("짐의 무게를 입력하세요 (kg): ");
    scanf_s("%lf", &baggage);

    if (people < 0 || people > 3 || baggage < 0) {
        printf("invalid input\n");
        return 0;
    }

    if (people == 0 && baggage > 0) {
        printf("invalid input\n");
        return 0;
    }

    total_weight = people * 70 + baggage;

    if (total_weight <= 600)
        printf("OK\n");
    else
        printf("Overload\n");

    printf("%s\n", (total_weight <= 600) ? "OK" : "Overload");

    return 0;
}