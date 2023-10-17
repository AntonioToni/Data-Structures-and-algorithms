#include <stdio.h>
#include <stdlib.h>

int* podniz(int *niz, int start, int stop)
{
    int i = 0;
    int n = stop - start;
    int *noviniz = malloc(sizeof(int)*n);
    for(start; start <= stop; start++)
    {
        noviniz[i] = niz[start];
        i++;
    }
    return noviniz;
}

int main()
{
    int i, niz[20] = {1,2,3,4,5,6,7,8,9};
    int start = 3;
    int stop = 6;
    int *noviniz = podniz(niz, start, stop);
    

    for(i = 0; i < stop - start;i++)
    {
        printf("%d ", noviniz[i]);
    }
	printf("\n");
	system("pause");
}