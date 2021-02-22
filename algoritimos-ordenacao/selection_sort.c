#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) \
	{               \
		int t;       \
		t = A;       \
		A = B;       \
		B = t;       \
	}

void selectionSort(int *V, int l, int r);

int main(void)
{
	int numArray[1000], i = 0;

	while (scanf("%d", &numArray[i]) != EOF)
		i++;

	selectionSort(numArray, 0, i - 1);

	printf("%d", numArray[0]);
	for (int j = 1; j < i; j++)
	{
		printf(" %d", numArray[j]);
	}
	printf("\n");

	return 0;
}

void selectionSort(int *V, int l, int r)
{
	int min, k;

	for (int i = l; i < r; i++)
	{
		min = i;
		for (int j = i + 1; j <= r; j++)
		{
			if (V[j] < V[min])
				min = j;
		}
		exch(V[i], V[min]);
	}
}

// 7 3 2 5 4 3