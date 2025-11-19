#include <stdio.h>

int main(void) {
    const double D = 0.05;      
    const double rho = 998.2;   
    const double mu = 0.001002;  
    double V;                    

    printf("유속 V (m/s)를 입력하세요: ");
    if (scanf_s("%lf", &V) != 1) {
        printf("invalid input\n");
        return 0;
    }

    if (V < 0) {
        printf("invalid input\n");
        return 0;
    }

    double Re = rho * V * D / mu;

    double q = 0.5 * rho * V * V;

    if (Re < 2300) {
        printf("유동 상태: 층류 (Laminar)\n");
    }
    else if (Re <= 4000) {
        printf("유동 상태: 천이 (Transitional)\n");
    }
    else {
        printf("유동 상태: 난류 (Turbulent)\n");
    }

    printf("Reynolds 수 = %.2f\n", Re);
    printf("동압 q = %.2f Pa\n", q);

    return 0;
}
