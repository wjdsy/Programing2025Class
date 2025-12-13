#include <stdio.h>
#include <math.h> 

#define DATA_SIZE 10

void printInputData(const double data[]) {
    int i;
    for (i = 0; i < DATA_SIZE; i++) {
        printf("%d번째 데이터 : %.0lf\n", i + 1, data[i]);
    }
}

void calculateRank(const double data[], int rank[]) {
    int i, j;

    for (i = 0; i < DATA_SIZE; i++) {
        int current_rank = 1;

        for (j = 0; j < DATA_SIZE; j++) {
 
            if (data[j] > data[i]) {
                current_rank++;
            }
        }
        rank[i] = current_rank;
    }
}

void printRankTable(const double data[], const int rank[]) {
    int i;

    printf("\n순번 | 입력값    | 순위\n");
    printf("---|-----------|---\n");

    for (i = 0; i < DATA_SIZE; i++) {
        printf(" %d | %7.3lf | %d\n", i + 1, data[i], rank[i]);
    }
}

void calculateAndPrintStatistics(const double data[]) {
    double sum = 0.0;
    double mean = 0.0;
    double variance_sum = 0.0;
    double variance = 0.0;
    double std_dev = 0.0;
    int i;

    for (i = 0; i < DATA_SIZE; i++) {
        sum += data[i];
    }
    mean = sum / DATA_SIZE;

    for (i = 0; i < DATA_SIZE; i++) {
        double diff = data[i] - mean;
        variance_sum += (diff * diff);
    }
 
    variance = variance_sum / DATA_SIZE;

    std_dev = sqrt(variance);

    printf("\n### 전체 데이터 통계 결과\n");
    printf("전체 데이터 평균: %.3lf\n", mean);
    printf("전체 데이터 분산: %.3lf\n", variance);
    printf("전체 데이터 표준 편차: %.3lf\n", std_dev);
}


int main() {
  
    double data[DATA_SIZE] = { 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0 };

    int rank[DATA_SIZE];

    printInputData(data);

    calculateRank(data, rank);

    printRankTable(data, rank);

    calculateAndPrintStatistics(data);

    return 0;
}