#include <stdio.h>

int main(void)
{

	for (int i = 2; i <= 9; i++)
	{
		for (unsigned int j = 2; j <= 9; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}