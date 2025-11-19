#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h> 

int main(void) {
    double theta;
    double g = 9.81;
    double mu_s = 0.5;
    double mu_k = 0.4;
    double theta_c;

    printf("경사각(도)을 입력하세요: ");
    scanf_s("%lf", &theta);

    if (theta < 0 || theta > 90) {
        printf("invalid input\n");
        return 0;
    }

    theta_c = atan(mu_s) * 180 / M_PI;

    if (theta <= theta_c) {
        printf("파렛트는 정지 상태입니다.\n");
        printf("임계각은 %.2f도입니다.\n", theta_c);
    }
    else {
        double rad = theta * M_PI / 180;
        double a = g * (sin(rad) - mu_k * cos(rad));
        printf("파렛트가 미끄러집니다!\n");
        printf("가속도는 %.2f m/s² 입니다.\n", a);
        printf("임계각은 %.2f도입니다.\n", theta_c);
    }

    return 0;
}
