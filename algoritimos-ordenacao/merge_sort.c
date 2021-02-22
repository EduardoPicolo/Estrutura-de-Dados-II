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

void merge(int *V, int l, int m, int r);
void mergesort(int *V, int l, int r);
int binarySearch(int *V, int l, int r, int x);

int main(void)
{
	int qnt = 0;
	int num;
	int numArray[140000];

	scanf("%d", &qnt);

	for (int i = 0; i < qnt; i++)
	{
		scanf("%d", &numArray[i]);
	}

	mergesort(numArray, 0, qnt - 1);

	while (scanf("%d", &num) != EOF)
	{
		if (binarySearch(numArray, 0, qnt - 1, num))
		{
			printf("sim\n");
		}
		else
		{
			printf("nao\n");
		}
	}

	return 0;
}

void merge(int *V, int l, int m, int r)
{
	int *R = malloc(sizeof(int) * (r - l + 1));
	int i = l, j = m + 1, k = 0;

	while (i <= m && j <= r)
	{
		if (lesseq(V[i], V[j]))
			R[k++] = V[i++];
		else
			R[k++] = V[j++];
	}

	while (i <= m)
		R[k++] = V[i++];
	while (j <= r)
		R[k++] = V[j++];

	k = 0;
	for (i = l; i <= r; i++)
		V[i] = R[k++];
	free(R);
};

void mergesort(int *V, int l, int r)
{
	if (l >= r)
		return;
	int meio = (l + r) / 2;
	mergesort(V, l, meio);
	mergesort(V, meio + 1, r);
	merge(V, l, meio, r);
};

int binarySearch(int *V, int l, int r, int x)
{
	int first = l, last = r, m = 0;

	while (first <= last)
	{
		m = (first + last) / 2;

		if (x == V[m])
		{
			return 1;
		}
		else if (x < V[m])
		{
			last = m - 1;
		}
		else if (x > V[m])
		{
			first = m + 1;
		}
	}

	return 0;
};
