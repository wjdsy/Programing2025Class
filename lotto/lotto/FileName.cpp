#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 상수 정의
#define LOTTO_SIZE 6  // 로또 일반 번호 개수
#define MAX_NUM 45    // 로또 번호 최대 값

// --- 함수 선언 ---
// 당첨 번호 6개와 보너스 번호 1개를 생성하는 함수
void generateWinningNumbers(int lotto[], int* bonus);

// 사용자로부터 번호 6개를 입력받는 함수 (간단한 유효성 검사만 포함)
void getUserInput(int user[]);

// 당첨 번호와 사용자 번호를 비교하고 결과를 출력하는 함수
void checkResult(const int lotto[], int bonus, const int user[]);

// --- 함수 정의 ---

// 로또 번호 생성 함수
void generateWinningNumbers(int lotto[], int* bonus) {
    bool used[MAX_NUM + 1] = { false }; // 중복 확인용 배열
    int count = 0;
    int rand_num;

    // 1. 일반 번호 6개 생성 (중복 제거)
    while (count < LOTTO_SIZE) {
        rand_num = (rand() % MAX_NUM) + 1; // 1 ~ 45 난수 생성
        if (!used[rand_num]) {
            lotto[count++] = rand_num;
            used[rand_num] = true;
        }
    }

    // 2. 보너스 번호 1개 생성 (일반 번호와 중복 제거)
    while (1) {
        rand_num = (rand() % MAX_NUM) + 1;
        if (!used[rand_num]) {
            *bonus = rand_num; // 포인터를 이용해 보너스 변수에 값 저장
            break;
        }
    }
}

// 사용자 번호 입력 함수
void getUserInput(int user[]) {
    printf(">>> 1부터 45 사이의 중복되지 않는 숫자 6개를 입력하세요.\n");

    for (int i = 0; i < LOTTO_SIZE; i++) {
        printf("번호 %d/%d 입력: ", i + 1, LOTTO_SIZE);
        // 간소화를 위해 중복 및 범위 검사는 최소화하고 입력만 받습니다.
        if (scanf_s("%d", &user[i]) != 1) {
            printf("잘못된 입력입니다. 프로그램을 다시 시작해주세요.\n");
            exit(1);
        }
    }
}

// 당첨 확인 및 결과 출력 함수
void checkResult(const int lotto[], int bonus, const int user[]) {
    int match_count = 0;
    bool bonus_match = false;

    // 1. 일치하는 일반 번호 개수 세기
    for (int i = 0; i < LOTTO_SIZE; i++) {
        for (int j = 0; j < LOTTO_SIZE; j++) {
            // 사용자 번호(user[i])와 당첨 번호(lotto[j]) 비교
            if (user[i] == lotto[j]) {
                match_count++;
                break;
            }
        }
    }

    // 2. 보너스 번호 일치 여부 확인
    for (int i = 0; i < LOTTO_SIZE; i++) {
        if (user[i] == bonus) {
            bonus_match = true;
            break;
        }
    }

    // --- 결과 출력 ---
    printf("\n*** 로또 당첨 결과 ***\n");
    printf("당첨 번호: ");
    for (int i = 0; i < LOTTO_SIZE; i++) {
        printf("%02d ", lotto[i]);
    }
    printf(" | 보너스: %02d\n", bonus);
    printf("나의 번호: ");
    for (int i = 0; i < LOTTO_SIZE; i++) {
        printf("%02d ", user[i]);
    }
    printf("\n-----------------------\n");
    printf("일치하는 일반 번호 개수: **%d개**\n", match_count);

    // 3. 당첨 등수 결정 (Switch-Case 대신 If-Else로 간결하게)
    if (match_count == 6) {
        printf("**1등 당첨!**\n");
    }
    else if (match_count == 5 && bonus_match) {
        printf("**2등 당첨!**\n");
    }
    else if (match_count == 5) {
        printf("**3등 당첨!**\n");
    }
    else if (match_count == 4) {
        printf("**4등 당첨!**\n");
    }
    else if (match_count == 3) {
        printf("**5등 당첨!**\n");
    }
    else {
        printf("**낙첨. 다음 기회에 도전하세요!**\n");
    }
}

// --- 메인 함수 ---
int main(void) {
    // 1. 난수 시드 설정
    srand((unsigned int)time(NULL));

    // 2. 변수 선언 (배열 사용)
    int winning_numbers[LOTTO_SIZE]; // 당첨 번호
    int bonus_number = 0;            // 보너스 번호
    int user_numbers[LOTTO_SIZE];    // 사용자 번호

    // 3. 당첨 번호 생성 (함수 사용, 포인터 사용)
    generateWinningNumbers(winning_numbers, &bonus_number);

    // 4. 사용자 번호 입력
    getUserInput(user_numbers);

    // 5. 당첨 확인 및 결과 출력 (함수 사용)
    checkResult(winning_numbers, bonus_number, user_numbers);

    // 프로그램 종료 대기
    printf("Press Enter to exit...\n");
    getchar(); // 남아있는 버퍼 비우기
    getchar(); // 사용자 입력을 기다림

    return 0;
}