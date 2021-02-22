#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B) \
	{               \
		int t;       \
		t = A;       \
		A = B;       \
		B = t;       \
	}
#define cmpexch(A, B) \
	{                  \
		if (less(B, A)) \
			exch(A, B);  \
	}

void insertionSort(int *V, int l, int r);

int main(void)
{
	int numArray[1000], i = 0;

	while (scanf("%d", &numArray[i]) != EOF)
		i++;

	insertionSort(numArray, 0, i - 1);

	printf("%d", numArray[0]);
	for (int j = 1; j < i; j++)
	{
		printf(" %d", numArray[j]);
	}
	printf("\n");

	return 0;
}

void insertionSort(int *V, int l, int r)
{
	for (int i = l+1; i <= r; i++) {
		for (int j = i; j > l ; j--) {
			cmpexch(V[j-1], V[j]);
		}
	}
}
