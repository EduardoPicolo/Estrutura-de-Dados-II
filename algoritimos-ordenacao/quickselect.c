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
int quickselect(int *v, int l, int r, int x);

int main(void)
{
	int numArray[1000], i = 0, x;

	while (scanf("%d", &numArray[i]) != EOF)
		i++;

	x = quickselect(numArray, 0, i - 1, 10);

	printf(" : %d \n", x);

	return 0;
}

int quickselect(int *v, int l, int r, int x)
{
	if (l >= r || r <= l)
		return -1;

	int j;
	cmpexch(v[(l + r) / 2], v[r]);
	cmpexch(v[l], v[(l + r) / 2]);
	cmpexch(v[r], v[(l + r) / 2]);
	j = separaSEDGEWICK(v, l, r);

	if (x == v[j])
		return v[j];
	else if (x < v[j]) {
		r = j-1;
	}
	else if (x > v[j]) {
		l = j+1;
	}

	quickselect(v, l, r, x);
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
