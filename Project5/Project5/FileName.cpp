#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int answer;  
    int guess;  
    int tries = 0;

    srand((unsigned int)time(NULL));  
    answer = rand() % 100 + 1;        

    printf("=== 업다운 게임 ===\n");
    printf("1부터 100 사이의 숫자를 맞춰보세요!\n");

    while (tries < 10) {  
        printf("\n숫자를 입력하세요 (%d번째 시도): ", tries + 1);
        scanf_s("%d", &guess);

        if (guess < 1 || guess > 100) { 
            printf("1~100 사이의 숫자만 입력하세요!\n");
            continue;
        }

        tries++;

        if (guess > answer) {
            printf("DOWN!\n");
        }
        else if (guess < answer) {
            printf("UP!\n");
        }
        else {
            printf("정답입니다! %d번 만에 맞추셨습니다!\n", tries);
            return 0;
        }
    }

    printf("\n10번의 기회를 모두 사용했습니다. 정답은 %d였습니다.\n", answer);

    return 0;
}
