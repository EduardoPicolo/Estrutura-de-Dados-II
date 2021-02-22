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
int removeDuplicates(int arr[], int n);
int binarySearch(int *V, int l, int r, int x);

int main(void)
{
	int n, k;

	scanf("%d", &n);

	int *numArray;

	numArray = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numArray[i]);
	}

	mergesort(numArray, 0, n - 1);

	k = removeDuplicates(numArray, n);


	if (!(k % 2 == 0))
	{
		numArray[k] = 1000000000;
		k++;
	}

	int sum = 0;
	int j = k;

	for (int i = 0; i < k; i += 2)
	{
		sum = numArray[i] + numArray[i + 1];
		if (binarySearch(numArray, 0, k - 1, sum))
			continue;
		else
		{
			numArray = realloc(numArray, (n  *2) * sizeof(int));
			numArray[j++] = sum;
		}
	}

	mergesort(numArray, 0, j - 1);

	for (int i = 0; i < j; i += 4)
	{
		printf("%d\n", numArray[i]);
	}
	printf("Elementos: %d\n", j);

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

int removeDuplicates(int arr[], int n)
{
	if (n == 0 || n == 1)
		return n;

	int j = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] != arr[i + 1])
			arr[j++] = arr[i];
	}
	arr[j++] = arr[n - 1];

	return j;
}

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
