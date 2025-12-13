#include <stdio.h>

#define MEMORY_SIZE 8

void simulate_struct() {
    char int_mem[MEMORY_SIZE];
    char double_mem[MEMORY_SIZE];

    int* p_int = (int*)int_mem;
    double* p_double = (double*)double_mem;

    printf("\n### 시뮬레이션 1: 구조체처럼 (독립된 메모리) ###\n");

    *p_int = 100;
    *p_double = 3.14159;

    printf("1) int 값과 double 값을 동시에 할당\n");
    printf("   int_mem (int)   : %d\n", *p_int);
    printf("   double_mem (double) : %lf\n", *p_double);

    printf("\n2) 메모리가 독립적이므로, 두 값이 모두 유지됨\n");
    printf("   int_mem (int)   : %d\n", *p_int);
    printf("   double_mem (double) : %lf\n", *p_double);
}

void simulate_union() {
    char shared_mem[MEMORY_SIZE];

    int* p_int = (int*)shared_mem;
    double* p_double = (double*)shared_mem;

    printf("\n\n### 시뮬레이션 2: 공용체처럼 (메모리 공유) ###\n");

    *p_int = 100;
    printf("1) int 공간에 100 할당 후:\n");
    printf("   int (p_int)   : %d\n", *p_int);

    *p_double = 99.99;

    printf("\n2) double 공간에 99.99 할당 후 (메모리 덮어쓰기):\n");
    printf("   double (p_double) : %lf\n", *p_double);

    printf("3) int를 다시 읽으면, double이 덮어쓴 데이터가 int로 해석됨\n");
    printf("   int (p_int)   : %d (값이 파괴됨)\n", *p_int);
}


int main() {
    printf("--- char 배열과 포인터를 이용한 구조체/공용체 메모리 시뮬레이션 ---\n");
    simulate_struct();
    simulate_union();
    return 0;
}