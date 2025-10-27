#include <stdio.h>

int res_func(int n)  
{
    if (n == 1)    
        return 1;
    else
        return n + res_func(n - 1); 
}

int main(void)
{
    int result;

    result = res_func(10);            
    printf("1부터 10까지의 합은 %d입니다.\n", result);

    return 0;
}