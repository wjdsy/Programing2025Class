#include <stdio.h>

// 함수 선언: 센티미터를 미터로 변환
double centi_to_meter(double cm);

int main(void)
{
    double res;

    res = centi_to_meter(187); 
    printf("%.2lfm\n", res);

    return 0;
}


double centi_to_meter(double cm)
{
    double meter;
    meter = cm / 100.0;
    return meter;      
}