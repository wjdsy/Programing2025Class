#include <stdio.h>

void swap_pointer(int* pnA, int* pnB);
void swap_normal(int nA, int nB);

int main(void)
{
	int nA = 0, nB = 0;
	nA = 10;
	nB = 20;

	int *pnA, *pnB;
	pnA = &nA;
	pnB = &nB;

	swap_pointer(pnA, pnB);
	//swap_normal(nA, nB);

	printf("before swap:(nA,nB)=(%d, %d)\n", nA, nB);
	return 0;
}

void swap_nomal(int nA, int nB)
{
	int nTemp = 0;
	nTemp = nA;
	nA = nB;
	nB = nTemp;
	printf("in the function:(nA,nB)=(%d, %d)\n", nA, nB);
}