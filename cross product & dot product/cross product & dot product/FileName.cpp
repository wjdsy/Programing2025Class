#include <stdio.h>
#include <stdlib.h> // exit() 함수를 위해 추가 (선택 사항)

/**
 * @brief 3차원 벡터 두 개의 내적(Dot Product)을 계산합니다.
 * * @param A 첫 번째 벡터 (배열 포인터)
 * @param B 두 번째 벡터 (배열 포인터)
 * @return double 내적 결과 (스칼라 값)
 */
double dot_product(double A[], double B[]) {
    // A · B = Ax*Bx + Ay*By + Az*Bz
    return A[0] * B[0] + A[1] * B[1] + A[2] * B[2];
}

/**
 * @brief 3차원 벡터 두 개의 외적(Cross Product)을 계산합니다.
 * * @param A 첫 번째 벡터
 * @param B 두 번째 벡터
 * @param C 외적 결과를 저장할 벡터 (C = A x B)
 */
void cross_product(double A[], double B[], double C[]) {
    // A x B = (Ay*Bz - Az*By, Az*Bx - Ax*Bz, Ax*By - Ay*Bx)
    C[0] = A[1] * B[2] - A[2] * B[1]; // i (x) 성분
    C[1] = A[2] * B[0] - A[0] * B[2]; // j (y) 성분
    C[2] = A[0] * B[1] - A[1] * B[0]; // k (z) 성분
}

int main(void) {
    // 3차원 벡터 선언 (double형 배열 사용)
    double vector_A[3];
    double vector_B[3];
    double vector_C[3]; // 외적 결과를 저장할 벡터 (A x B)

    // 1. 벡터 A 입력
    printf("--- 3차원 벡터 계산기 ---\n");
    printf("첫 번째 벡터 A(Ax Ay Az)를 입력하세요 (예: 1.0 2.0 3.0): ");
    if (scanf_s("%lf %lf %lf", &vector_A[0], &vector_A[1], &vector_A[2]) != 3) {
        printf("오류: 벡터 A 입력이 올바르지 않습니다.\n");
        return 1;
    }

    // 2. 벡터 B 입력
    printf("두 번째 벡터 B(Bx By Bz)를 입력하세요 (예: 4.0 5.0 6.0): ");
    if (scanf_s("%lf %lf %lf", &vector_B[0], &vector_B[1], &vector_B[2]) != 3) {
        printf("오류: 벡터 B 입력이 올바르지 않습니다.\n");
        return 1;
    }

    // 3. 내적 계산 (함수 사용)
    double dot_res = dot_product(vector_A, vector_B);

    // 4. 외적 계산 (함수 및 포인터/배열 사용)
    cross_product(vector_A, vector_B, vector_C);

    // 5. 결과 출력 및 검증 요청
    printf("\n--- 계산 결과 ---\n");
    printf("벡터 A: (%.2lf, %.2lf, %.2lf)\n", vector_A[0], vector_A[1], vector_A[2]);
    printf("벡터 B: (%.2lf, %.2lf, %.2lf)\n", vector_B[0], vector_B[1], vector_B[2]);

    printf("\n** 내적 (Dot Product) A · B **\n");
    printf("결과 (스칼라): **%.4lf**\n", dot_res);

    printf("\n** 외적 (Cross Product) A x B **\n");
    printf("결과 (벡터): **(%.4lf, %.4lf, %.4lf)**\n",
        vector_C[0], vector_C[1], vector_C[2]);

    printf("\n이 결과를 공학용 계산기나 온라인 계산기로 확인해 보시기 바랍니다.\n");

    return 0;
}