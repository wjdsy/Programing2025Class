#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    
#include <math.h>     

void generateNumbers(int arr[], int n, int min, int max);
int sumArray(int arr[], int n);
double variance(int arr[], int n, double mean);

int main(void) {
    int numbers[10];        
    int n = 10;            
    int min, max;         
    int total;               
    double mean, var, std; 

    srand((unsigned int)time(NULL));

    printf("난수를 생성할 최소값을 입력하세요: ");
    scanf_s("%d", &min);
    printf("난수를 생성할 최대값을 입력하세요: ");
    scanf_s("%d", &max);

    if (min >= max) {
        printf("invalid input (최소값은 최대값보다 작아야 함)\n");
        return 0;
    }

    generateNumbers(numbers, n, min, max);

    printf("\n생성된 난수들: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    total = sumArray(numbers, n);
    mean = (double)total / n;

    var = variance(numbers, n, mean);

    std = sqrt(var);

    printf("\n총합: %d\n", total);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", var);
    printf("표준편차: %.2f\n", std);

    return 0;
}

void generateNumbers(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double variance(int arr[], int n, double mean) {
    double var = 0.0;
    for (int i = 0; i < n; i++) {
        var += pow(arr[i] - mean, 2);
    }
    return var / n;
}
