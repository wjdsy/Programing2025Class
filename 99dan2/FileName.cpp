#include <stdio.h>

int main(void)
{
    int dan;

    printf("구구단 입력 (2-9 단, 전체는 0 입력): ");


    if (scanf_s("%d", &dan) != 1)
    {
        printf("유효한 숫자를 입력하세요.\n");
        return 0;
    }

    if (dan == 0)
    {
        printf("\n=== 2단 - 9단 전체 구구단 출력 ===\n");


        for (int i = 2; i <= 9; i++)
        {
            printf("\n--- %d 단 ---\n", i);

            for (int j = 1; j <= 9; j++)
            {
                printf("%d x %d = %d\n", i, j, i * j);
            }
        }
    }
   
    else if (dan >= 2 && dan <= 9)
    {
        printf("\n--- %d 단 ---\n", dan);
        for (int j = 1; j <= 9; j++)
        {
            printf("%d x %d = %d\n", dan, j, dan * j);
        }
    }
  
    else
    {
        printf("0(전체) 또는 2에서 9 사이의 숫자를 입력해야 합니다.\n");
    }

    return 0;
}