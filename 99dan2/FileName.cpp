#include <stdio.h>

int main(void)
{
    int dan;

    printf("������ �Է� (2-9 ��, ��ü�� 0 �Է�): ");


    if (scanf_s("%d", &dan) != 1)
    {
        printf("��ȿ�� ���ڸ� �Է��ϼ���.\n");
        return 0;
    }

    if (dan == 0)
    {
        printf("\n=== 2�� - 9�� ��ü ������ ��� ===\n");


        for (int i = 2; i <= 9; i++)
        {
            printf("\n--- %d �� ---\n", i);

            for (int j = 1; j <= 9; j++)
            {
                printf("%d x %d = %d\n", i, j, i * j);
            }
        }
    }
   
    else if (dan >= 2 && dan <= 9)
    {
        printf("\n--- %d �� ---\n", dan);
        for (int j = 1; j <= 9; j++)
        {
            printf("%d x %d = %d\n", dan, j, dan * j);
        }
    }
  
    else
    {
        printf("0(��ü) �Ǵ� 2���� 9 ������ ���ڸ� �Է��ؾ� �մϴ�.\n");
    }

    return 0;
}