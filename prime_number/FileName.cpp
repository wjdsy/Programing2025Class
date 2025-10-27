#include <stdio.h>

int main(void)
{
    int n, i, j;          
    int count = 0;        

    printf("2 이상의 정수를 입력하세요: ");
    scanf_s("%d", &n);

    if (n < 2)
    {
        printf("2 이상의 정수를 입력해야 합니다.\n");
        return 0;
    }

   
    for (i = 2; i <= n; i++)
    {
        int Prime = 1;

        
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                Prime = 0;
                break;
            }
        }

        
        if (Prime)
        {
            printf("%5d", i); 
            count++;

            
            if (count % 5 == 0)
                printf("\n");
        }
    }

    printf("\n"); 
    return 0;
}