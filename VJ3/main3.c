#include <stdlib.h>
#include<stdio.h>
#include<time.h>
int cmp(const void* a, const void* b)
{
     return (*(int*)a - *(int*)b);
}
int* generiraj(int n) {
    int* niz = (int*)malloc(sizeof(int) * n);
    niz[0] = rand() % 5;
    for (int i = 1; i < n; i++) {
        niz[i] = niz[i - 1] + 1 + rand() % 5;
    }
    return niz;
}
int* presjek(int *a, int *b, int m,int *br)
{
    int i, j;
    int k = 0;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (a[i] == b[j])
                (*br)++;
        }
    }
    int* c = (int*)malloc(sizeof(int) * (*br));
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
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
int* presjek_jedan_sortiran(int* a, int* b, int m, int* br)
{
    qsort(b, m, sizeof(int), cmp);
    int i, j=0;
    int k = 0;
    int* c = (int*)malloc(sizeof(int) * (m * 2));
    for (i = 0; i < m; ++i)
    {
        int* br = (int*)bsearch(&(a[i]), b, m, sizeof(int), cmp);
        if (br != NULL)
        {
            c[j] = a[i];
            ++j;
        }
    }

    return c;
}
int* presjek_oba_sortirana(int* a, int* b, int m, int* br)
{
    qsort(a, m, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    int i = 0, j = 0, k = 0;
    while (i < m && j < m) {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            (*br)++;
            i++;
            j++;
        }
    }
    i = 0, j = 0;
    int* c = (int*)malloc(sizeof(int) * (*br));
    while (i < m && j < m) {
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
    free(a);
    free(b);
    return c;
}
void shuffle(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        int j = (rand() * rand()) % n;
        int tmp = niz[i];
        niz[i] = niz[j];
        niz[j] = tmp;
    }
}
int main()
{
    clock_t start_t, end_t, total_t;
    clock_t start_t1, end_t1, total_t1;
    clock_t start_t2, end_t2, total_t2;
    srand(time(NULL));
    int br = 0;
    int n = 10000;
    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);
    int *a=generiraj(n);
    shuffle(a, n);
    int* b = generiraj(n);
    shuffle(b, n);
    int* c,*d,*e;
    c = presjek(a,b,n,&br);
    end_t = clock();
    total_t = (long int)(end_t - start_t);
    printf("Total time taken by CPU: %lu\n", total_t);
    start_t1 = clock();
    printf("Starting of the program, start_t1 = %ld\n", start_t1);
    d= presjek_jedan_sortiran(a, b, n, &br);
    end_t1 = clock();
    total_t1 = (long int)(end_t1 - start_t1);
    printf("Total time taken by CPU 1: %lu\n", total_t1);
    start_t2 = clock();
    printf("Starting of the program, start_t1 = %ld\n", start_t2);
    e= presjek_oba_sortirana(a, b, n, &br);
    end_t2 = clock();
    total_t2 = (long int)(end_t2 - start_t2);
    printf("Total time taken by CPU 2: %lu\n", total_t2);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    system("pause");
    return 0;
}