#include <stdio.h>


void calculate_line_parameters(const double* p1_x, const double* p1_y,
    const double* p2_x, const double* p2_y,
    double* slope_ptr, double* bias_ptr) {

    
    double x1 = *p1_x;
    double y1 = *p1_y;
    double x2 = *p2_x;
    double y2 = *p2_y;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double slope;
    double bias;

    if (dx == 0.0) {
        
        printf("경고: x좌표가 동일합니다 (수직선). 기울기 계산이 부정확할 수 있습니다.\n");
        slope = 0.0; // 임의 값 할당
    }
    else {
       
        slope = dy / dx;
    }

    
    bias = y1 - slope * x1;

    
    *slope_ptr = slope;
    *bias_ptr = bias;
}

int main() {
    
    double x1, y1, x2, y2;

   
    double calculated_slope;
    double calculated_bias;

    
    printf("Input 1st point information (x1 y1): ");
    
    if (scanf_s("%lf %lf", &x1, &y1) != 2) {
        printf("입력 오류. 프로그램을 종료합니다.\n");
        return 1;
    }

    printf("Input 2nd point information (x2 y2): ");
    if (scanf_s("%lf %lf", &x2, &y2) != 2) {
        printf("입력 오류. 프로그램을 종료합니다.\n");
        return 1;
    }

   
    calculate_line_parameters(&x1, &y1, &x2, &y2,
        &calculated_slope, &calculated_bias);

   
    printf("\nCalculated Output, line equation:\n");
    printf("slope: %.4f\n", calculated_slope);
    printf("bias: %.4f\n", calculated_bias);

    return 0;
}