#include <stdio.h>

void calculateLine(double x_coords[], double y_coords[]) {
    double x1 = x_coords[0];
    double y1 = y_coords[0];
    double x2 = x_coords[1];
    double y2 = y_coords[1];

    double delta_x = x2 - x1;
    double delta_y = y2 - y1;

    double slope;
    double bias;

    if (delta_x != 0.0) {
  
        slope = delta_y / delta_x;

        bias = y1 - (slope * x1);
    }
    else {
        slope = 99999.0;
        bias = x1;
    }

    printf("\nCalculated Output, line equation:\n");
    printf("slope: %.4lf\n", slope);
    printf("bias: %.4lf\n", bias);
}

int main() {
    double x[2];
    double y[2];

    printf("Input 1st point information:\n");
    if (scanf_s("%lf %lf", &x[0], &y[0]) != 2) {
        printf("Invalid input for 1st point.\n");
        return 1;
    }

    printf("\nInput 2nd point information:\n");
    if (scanf_s("%lf %lf", &x[1], &y[1]) != 2) {
        printf("Invalid input for 2nd point.\n");
        return 1;
    }

    calculateLine(x, y);

    return 0;
}