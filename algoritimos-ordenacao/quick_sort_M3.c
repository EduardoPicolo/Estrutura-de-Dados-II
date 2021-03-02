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

int separaSEDGEWICK(int *V, int l, int r);
//int separaCORMEM(int *V, int l, int r);
void quicksort(int *V, int l, int r);

int main(void)
{
	int numArray[1000], i = 0;

	while (scanf("%d", &numArray[i]) != EOF)
		i++;

	quicksort(numArray, 0, i - 1);

	printf("%d", numArray[0]);
	for (int j = 1; j < i; j++)
	{
		printf(" %d", numArray[j]);
	}
	printf("\n");

	return 0;
}

void quicksort(int *V, int l, int r)
{
	if (r <= l)
		return;
	int j;
	cmpexch(V[(l + r) / 2], V[r]);
	cmpexch(V[l], V[(l + r) / 2]);
	cmpexch(V[r], V[(l + r) / 2]);
	j = separaSEDGEWICK(V, l, r);
	quicksort(V, l, j - 1);
	quicksort(V, j + 1, r);
}

int separaSEDGEWICK(int *V, int l, int r)
{
	int i = l - 1, j = r;
	int v = V[r];
	for (;;)
	{
		while (less(V[++i], v))
			;
		while (less(v, V[--j]))
			if (j == l)
				break;
		if (i >= j)
			break;
		exch(V[i], V[j]);
	}
	exch(V[i], V[r]) return i;
}

// int separaCORMEM(int *V, int l, int r)
// {
// 	int c = V[r];
// 	int j = l;
// 	for (int k = l; k < r; k++)
// 		if (less(V[k], c))
// 		{
// 			exch(V[k], V[j]);
// 			j++;
// 		}
// 	exch(V[j], V[r]);
// 	return j;
// }