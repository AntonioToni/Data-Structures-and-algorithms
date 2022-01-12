#include <stdio.h>
#include <stdlib.h>

int* filtriraj(int *niz, int n, int th, int *nth)
{
	int i, cnt = 0;
	for (i = 0; i <= n; i++)
	{
		if (niz[i] < th)
		{
			cnt++;
		}
	}
	nth = malloc(cnt * sizeof(int));
	cnt = 0;
	for (i = 0; i <= n; i++)
	{
		if (niz[i] < th)
		{
			nth[cnt] = niz[i];
			cnt++;
		}
	}
	return nth;
}

int main()
{
	int n = 9, th = 5, *nth;
	int niz[9] = { 1,2,3,4,5,6,7,8,9 };
	nth = filtriraj(niz, n, th, nth);
	int i;
	int m = sizeof(nth);
	for (i = 0; i < m; i++)
	{
		printf("%d ", nth[i]);
	}
	free(nth);
}