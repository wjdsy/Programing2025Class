#include <stdio.h>

int main() {
    int a, b;

    
    printf("�� ���� ������ �Է��ϼ���: ");
    scanf_s("%d %d", &a, &b);

   
    a++;
    --b;

    
    printf("\n[���� ���� ���]\n");
    if (a > b)
        printf("a(%d)�� b(%d)���� Ů�ϴ�.\n", a, b);
    else if (a < b)
        printf("a(%d)�� b(%d)���� �۽��ϴ�.\n", a, b);
    else
        printf("a�� b�� �����ϴ�.\n");

   
    printf("\n[�� ���� ���]\n");
    if (a > 0 && b > 0)
        printf("a�� b ��� ����Դϴ�.\n");
    if (a < 0 || b < 0)
        printf("a �Ǵ� b �� �ϳ��� �����Դϴ�.\n");
    if (!(a == b))
        printf("a�� b�� ���� �ٸ��ϴ�.\n");

   
    printf("\n���� ���� ������ ��: a = %d, b = %d\n", a, b);

    return 0;
}