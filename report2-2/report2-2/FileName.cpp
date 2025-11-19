#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double temp;    
    int door;      
    int time;       

    printf("문 상태를 입력하세요 (0: 닫힘, 1: 열림): ");
    scanf_s("%d", &door);
    printf("경과 시간을 입력하세요 (초): ");
    scanf_s("%d", &time);
    printf("현재 온도를 입력하세요 (°C): ");
    scanf_s("%lf", &temp);

    if ((door != 0 && door != 1) || time < 0 || temp < -50 || temp > 50) {
        printf("invalid input\n");
        return 0;
    }

    if (door == 0) { 
        if (temp >= 2.0 && temp <= 8.0) {
            printf("Normal\n");
        }
        else if (time <= 30) {
            printf("Warning\n");
        }
        else {
            printf("Critical\n");
        }
    }
    else { 
        if (time >= 60 && (temp < 2.0 || temp > 8.0)) {
            printf("Critical\n");
        }
        else {
            printf("Warning\n");
        }
    }

    return 0;
}
