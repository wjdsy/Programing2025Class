#include <stdio.h>

int main() {
    // 1. 변수 선언 및 초기화
    // 정수 10개를 저장할 배열
    int ary[10];
    // 각 값의 순위를 저장할 배열
    int rank_array[10];

    // 통계량 변수는 선언과 동시에 0.0으로 초기화
    double sum = 0.0;
    double mean = 0.0;
    double variance = 0.0;
    double total_squared_diff = 0.0;

    const int count = 10;

    // 2. 데이터 입력 (scanf 및 int 배열 사용)
    printf("===========================================\n");
    printf("정수 %d개를 입력하세요:\n", count);
    for (int i = 0; i < count; i++) {
        printf("데이터 #%d: ", i + 1);
        // scanf로 정수 입력
        scanf_s("%d", &ary[i]);
        sum += (double)ary[i]; // 합계 계산 (double로 형 변환)
        rank_array[i] = 1;    // 순위 초기화
    }
    printf("===========================================\n");

    // 3. 순위 (Rank) 계산
    // 나보다 큰 데이터의 개수를 세어 순위를 매김
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (ary[i] < ary[j]) {
                rank_array[i]++;
            }
        }
    }

    // 4. 통계량 계산

    // 4-1. 평균 (Mean) 계산
    mean = sum / count;

    // 4-2. 분산 (Variance) 계산을 위한 편차 제곱의 합계 계산
    for (int i = 0; i < count; i++) {
        double difference = (double)ary[i] - mean;
        total_squared_diff += difference * difference;
    }
    variance = total_squared_diff / count;

    // 5. 결과 출력 (요청하신 형식에 맞춤)
    printf("\n");
    printf("순번    입력값    순위\n");
    printf("---------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%4d    %6d    %4d\n", i + 1, ary[i], rank_array[i]);
    }
    printf("---------------------------\n");

    printf("전체 데이터의 평균: %.4f\n", mean);
    printf("전체 데이터의 분산: %.4f\n", variance);
    // 표준편차는 math.h가 없으므로 계산할 수 없습니다.
    printf("전체 데이터의 표준편차: 수학 라이브러리 없이 계산 불가\n");

    // Visual Studio에서 결과를 확인하려면, 프로그램이 바로 종료되지 않도록 다음 코드를 추가할 수 있습니다.
    // system("pause"); // Windows 콘솔에서 일시 정지 (선택 사항)

    return 0;
}