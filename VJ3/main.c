#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generiraj(int n) 
{
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) 
{
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* presjek(int* a, int* b, int m, int* cnt)
{
    int i, j;
    int k = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
                (*cnt)++;
        }
    }
    int* c = (int*)malloc(sizeof(int) * (*cnt));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                c[k] = a[i];
                k++;
            }
        }
    }
    return c;
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int* presjek1sort(int* a, int* b,int m, int* cnt)
{
	int i, j = 0;
	qsort(b, m, sizeof(int), cmp);
	int* c = (int*)malloc(sizeof(int) * (m*2));
	for (i = 0; i < m; i++)
	{
		int* br = (int*)bsearch(&(a[i]), b, m, sizeof(int), cmp);
		if (br != NULL)
		{
			c[j] = a[i];
			j++;
		}
	}
	*cnt = j;
	return c;
}

int* presjek2sort(int* a, int* b, int m, int* cnt)
{
    qsort(a, m, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    int i = 0, j = 0, k = 0;
    while (i < m && j < m) 
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            (*cnt)++;
            i++;
            j++;
        }
    }
    i = 0, j = 0;
    int* c = (int*)malloc(sizeof(int) * (*cnt));
    while (i < m && j < m) 
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            c[k] =a[i];
            i++;
            j++;
            k++;
        }
    }
    return c;
}

int main()
{
	clock_t start_t, end_t, total_t;
	srand(time(NULL));
	int cnt = 0;
	int n = 300000;
	
	start_t = clock();
    int *a = generiraj(n);
	shuffle(a, n);
	int *b = generiraj(n);
	shuffle(b, n);
	int *p = presjek(a, b, n, &cnt);
	end_t = clock();
	total_t = (long int)(end_t - start_t);
	printf("CPU time: %lu ms\n", total_t);

	start_t = clock();
	int *p1 = presjek1sort(a, b, n, &cnt);
	end_t = clock();
	total_t = (long int)(end_t - start_t);
	printf("CPU time: %lu ms\n", total_t);

	start_t = clock();
	int *p2 = presjek2sort(a, b, n, &cnt);
	end_t = clock();
	total_t = (long int)(end_t - start_t);
	printf("CPU time: %lu ms\n", total_t);

	free(a);
	free(b);
	free(p);
	free(p1);
	free(p2);
    system("pause");
}