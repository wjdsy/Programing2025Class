#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 3x3 행렬 크기를 상수로 정의합니다.
#define SIZE 3 

// 행렬을 출력하는 함수
void print_matrix(const char* name, int M[SIZE][SIZE]) {
    printf("\n--- %s ---\n", name);
    for (int i = 0; i < SIZE; i++) { // i는 행 (Row)을 담당
        for (int j = 0; j < SIZE; j++) { // j는 열 (Column)을 담당
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}

// 덧셈 (A + B) 함수
void add_matrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    // R[i][j] = A[i][j] + B[i][j]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 뺄셈 (A - B) 함수
void subtract_matrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    // R[i][j] = A[i][j] - B[i][j]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}

// 스칼라 곱셈 (k * A) 함수
void scalar_multiply(int k, int A[SIZE][SIZE], int R[SIZE][SIZE]) {
    // R[i][j] = k * A[i][j]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            R[i][j] = k * A[i][j];
        }
    }
}

// **가장 복잡한** 행렬 곱셈 (A * B) 함수
void multiply_matrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { // 결과 행렬 R의 행 (Row)
        for (int j = 0; j < SIZE; j++) { // 결과 행렬 R의 열 (Column)
            R[i][j] = 0; // 곱셈 결과의 초기화
            // A의 i번째 행과 B의 j번째 열을 내적합니다.
            for (int k = 0; k < SIZE; k++) { // 곱셈 연산에 사용될 인덱스
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 역행렬 존재 여부를 확인하기 위한 3x3 행렬식(Determinant) 계산 함수
int calculate_determinant(int A[SIZE][SIZE]) {
    // 사루스 공식 (Sarrus' rule)을 사용합니다.
    // det(A) = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) 
    //        - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) 
    //        + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0])

    int det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
        - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
        + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    return det;
}

// 메인 함수
int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE];
    int C[SIZE][SIZE]; // 모든 연산 결과를 저장할 결과 행렬
    int scalar;

    // 난수 생성 시드 설정
    srand(time(NULL));

    // 행렬 A, B와 스칼라 무작위 생성 (-5 ~ 5 범위의 정수)
    scalar = rand() % 5 + 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = (rand() % 11) - 5;
            B[i][j] = (rand() % 11) - 5;
        }
    }

    // --- 1. 입력 확인 ---
    printf("--- 무작위 생성 데이터 ---\n");
    printf("\n스칼라 (k): %d", scalar);
    print_matrix("행렬 A", A);
    print_matrix("행렬 B", B);
    printf("==========================================");

    // --- 2. 덧셈 (A + B) ---
    add_matrices(A, B, C);
    print_matrix("1. 덧셈 (A + B)", C);

    // --- 3. 뺄셈 (A - B) ---
    subtract_matrices(A, B, C);
    print_matrix("2. 뺄셈 (A - B)", C);

    // --- 4. 스칼라 곱셈 (k * A) ---
    scalar_multiply(scalar, A, C);
    printf("\n--- 3. 스칼라 곱셈 (%d * A) ---", scalar);
    print_matrix("결과", C);

    // --- 5. 행렬 곱셈 (A * B) ---
    multiply_matrices(A, B, C);
    print_matrix("4. 행렬 곱셈 (A @ B)", C);

    // --- 6. 역행렬 계산 가능 여부 확인 ---
    int det_A = calculate_determinant(A);
    printf("\n--- 5. 역행렬 계산 가능 여부 (행렬 A) ---\n");
    printf("행렬식 (Determinant) det(A):%d\n", det_A);

    if (det_A != 0) {
        printf("행렬식이 0이 아니므로 역행렬이 존재합니다.\n");
    }
    else {
        printf("행렬식이 0이므로 역행렬이 존재하지 않습니다.\n");
    }
    printf("==========================================\n");

    return 0;
}