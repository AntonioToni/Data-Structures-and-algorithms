#include <stdio.h>

int** podijeli(int *niz, int n) 
{
	int i;
	int **noviniz = malloc(2 * sizeof(int));
	noviniz[0] = malloc(n / 2 * sizeof(int));
	noviniz[1] = malloc((n / 2 + 1) * sizeof(int));
	for(i = 0; i < n / 2; i++)
	{
		noviniz[0][i] = niz[i];
	}
	int j = 0;
	for(i = n / 2; i < n+1; i++)
	{
		noviniz[1][j] = niz[i];
		j++;
	}
	return noviniz;
}

int main()
{
	int n = 9;
	int niz[9] = { 1,2,3,4,5,6,7,8,9};
	int **noviniz = podijeli(niz, n);
    int i, j;
	for (i = 0; i < 2; i++)
    {
		printf("%d. niz: \n", i);
		for (j = 0; j < (n/2); j++)
	    {
	    	printf("%d ", noviniz[i][j]);
	    }
		//za neparan broj brojeva u nizu
		if (n / 2 != 0)
		{
			n++;
		}
		printf("\n");
    }
	free(noviniz);
}