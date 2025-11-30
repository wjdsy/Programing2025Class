#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

// 배열 크기 및 범위 상수 정의
#define ARRAY_SIZE 100    // 전체 배열 크기 (0 ~ 99)
#define RANGE_LIMIT 1000  // ⭐ 난수 생성 범위 (0 ~ 999)로 다시 변경
#define SUB_ARRAY_SIZE 10 // 추출할 정수의 개수

// --- 난수 생성 관련 함수 ---
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 특정 범위 이내의 난수 생성: RANGE_LIMIT(1000)을 nRange로 받으면 0~999 난수 생성
unsigned int GenRandNum(unsigned int nRange)
{
    return rand() % nRange;
}

// --- 통계 계산 함수 (배열/포인터/함수 사용) ---
// 총합 계산
double CalcSum(const int* arr, int nStartIndex)
{
    double dSum = 0.0;
    for (int i = 0; i < SUB_ARRAY_SIZE; i++)
    {
        dSum += *(arr + nStartIndex + i);
    }
    return dSum;
}

// 평균 계산
double CalcAverage(double dSum)
{
    return dSum / SUB_ARRAY_SIZE;
}

// 분산 계산
double CalcVariance(const int* arr, int nStartIndex, double dAverage)
{
    double dSumOfSquaredDiff = 0.0;

    for (int i = 0; i < SUB_ARRAY_SIZE; i++)
    {
        int nValue = *(arr + nStartIndex + i);
        double dDiff = nValue - dAverage;
        dSumOfSquaredDiff += (dDiff * dDiff);
    }

    return dSumOfSquaredDiff / SUB_ARRAY_SIZE;
}

// 표준편차 계산
double CalcStdDev(double dVariance)
{
    return sqrt(dVariance);
}

// --- 메인 함수 ---

int main(void)
{
    GenRandSeed();
    int nRandNums[ARRAY_SIZE];

    // 1. 100개의 난수 생성 (0부터 999까지)
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // RANGE_LIMIT이 1000이므로 0~999의 난수가 생성됩니다.
        nRandNums[i] = GenRandNum(RANGE_LIMIT);
    }

    // 2. 100개의 난수를 출력하여 사용자에게 보여주기
    printf("**총 %d개의 무작위 정수 목록 (범위: 0 ~ %d)**\n", ARRAY_SIZE, RANGE_LIMIT - 1);
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // 인덱스와 값을 모두 출력하도록 포맷 수정
        printf("[**%02d**]: %-5d", i, nRandNums[i]);

        if ((i + 1) % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("-----------------------------------------------------------------------\n");

    // 3. 사용자로부터 범위 입력 받기
    // 3. 사용자로부터 범위 입력 받기
    int nStartIndex;
    int nEndIndex;

    const int MAX_START_INDEX = ARRAY_SIZE - SUB_ARRAY_SIZE;

    while (1)
    {
        printf("\n⭐ 통계를 계산할 **10개의 정수 범위**를 지정하세요.\n");
        printf("시작 인덱스(0부터 시작)는 **0 ~ %d** 사이여야 합니다.\n", MAX_START_INDEX);

        printf("시작 인덱스 입력: ");

        // scanf_s를 사용하여 입력 시도
        if (scanf_s("%d", &nStartIndex) != 1) {
            printf("입력 오류. 유효한 **단일 숫자**를 입력하세요.\n");
            // 입력 버퍼에 남아있는 모든 문자(줄 바꿈 포함)를 비움
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue; // 루프의 처음으로 돌아가 재입력 요청
        }

        // 입력 버퍼에 남아있는 데이터가 있는지 확인하고 모두 비움
        // 사용자가 '201 4 60 1 3...'처럼 여러 숫자를 입력했을 때,
        // 첫 번째 숫자(201)만 읽고 나머지 ' 4 60...'를 모두 비워줍니다.
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        nEndIndex = nStartIndex + SUB_ARRAY_SIZE - 1;

        // 유효 범위 검사
        if (nStartIndex < 0 || nStartIndex > MAX_START_INDEX)
        {
            printf("입력된 시작 인덱스(%d)가 유효한 범위(0 ~ %d)를 벗어났습니다. 다시 시도하세요.\n",
                nStartIndex, MAX_START_INDEX);
            continue; // 루프의 처음으로 돌아가 재입력 요청
        }

        break; // 유효한 입력 시 루프 종료
    }

    // 4. 통계 계산 및 출력
    printf("\n---  선택된 10개의 정수 (인덱스 %d ~ %d) ---\n", nStartIndex, nEndIndex);
    for (int i = nStartIndex; i <= nEndIndex; i++) {
        printf("%d ", nRandNums[i]);
    }
    printf("\n-------------------------------------------------\n");

    double dSum = CalcSum(nRandNums, nStartIndex);
    double dAverage = CalcAverage(dSum);
    double dVariance = CalcVariance(nRandNums, nStartIndex, dAverage);
    double dStdDev = CalcStdDev(dVariance);

    printf("**최종 통계 결과**\n");
    printf("* 총합 (Sum): **%.2f**\n", dSum);
    printf("* 평균 (Average): **%.2f**\n", dAverage);
    printf("* 분산 (Variance): **%.2f**\n", dVariance);
    printf("* 표준편차 (Standard Deviation): **%.2f**\n", dStdDev);

    return 0;
}