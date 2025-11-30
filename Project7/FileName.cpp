#include <stdio.h> 

#define SIZE 10

// 배열의 요소를 사용자로부터 입력받아 초기화하는 함수
void InitializeArray(double* arr, int size) {
    printf("--- 배열 요소 입력 ---\n");
    printf("실수값 %d개를 입력하세요 (예: 10.5 30.0 -20.1 ...): ", size);

    // 반복문을 통해 10개의 값을 순차적으로 입력받음
    for (int i = 0; i < size; i++) {
        // scanf는 공백을 기준으로 값을 구분하므로, 한 번의 입력으로 10개 값을 받을 수 있습니다.
        if (scanf_s("%lf", &arr[i]) != 1) {
            printf("\n잘못된 입력 형식입니다. 프로그램을 종료합니다.\n");
            return;
        }
    }
}

// 배열을 출력하는 함수 (오직 포인터 문법만 사용하여 출력)
void PrintArray(double* arr, int size, const char* desc) {
    printf("--- %s ---\n", desc);
    for (int i = 0; i < size; i++) printf("[%.2lf] ", *(arr + i));
    printf("\n\n");
}

// 배열을 오름차순/내림차순으로 정렬하는 함수
void CalcSortArray(double* arr, int size, int isAscending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // 비교 시 배열 문법 arr[j] 사용
            double current = arr[j], next = arr[j + 1], temp;

            int needSwap = isAscending ? (current > next) : (current < next);
            if (needSwap) {
                // 교환 시 포인터 문법 *(arr + j) 사용
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    double numbers[SIZE];

    // 1. 사용자 입력으로 배열 초기화
    InitializeArray(numbers, SIZE);
    PrintArray(numbers, SIZE, "사용자 입력 상태");

    // 2. 오름차순 정렬 및 출력
    CalcSortArray(numbers, SIZE, 1);
    PrintArray(numbers, SIZE, "오름차순 정렬");

    // 3. 내림차순 정렬 및 출력
    CalcSortArray(numbers, SIZE, 0);
    PrintArray(numbers, SIZE, "내림차순 정렬");

    return 0;
}