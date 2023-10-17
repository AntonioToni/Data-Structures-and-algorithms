#include <stdio.h>
#include<stdlib.h>

struct Tocka
{
    float x, y;
};

struct Poligon
{
    struct Tocka *vrh;
    int n;
};

struct Poligon* novi_poligon(float *niz_x, float *niz_y, int n)
{
    struct Poligon *pol;
    pol -> vrh = malloc(sizeof(struct Tocka) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        pol -> vrh[i].x = niz_x[i];
        pol -> vrh[i].y = niz_y[i];
    }
    pol->n = n;
    return pol;
}

struct Tocka** pozitivni(struct Poligon *p, int *np)
{
    int i, vel = 0;
    for (i = 0; i < p->n; i++)
    {
        if (p -> vrh[i].x > 0 && p -> vrh[i].y > 0)
        {
            vel++;
        }
    }
    struct Tocka** poz = malloc(vel * sizeof(struct Tocka));
    int j = 0;
    for (i = 0; i < p->n; i++)
    {
        if (p -> vrh[i].x > 0 && p -> vrh[i].y > 0)
        {
            poz[j] = p -> vrh + i;
            j++;
        }
    }
    *np = vel;
    return poz;
}

int main()
{
    float niz_x[] = { -1, 5, 2, -6, 3};
    float niz_y[] = { -1, 2, -3, 4, 6};
    int n = 5;
    int np;
    struct Poligon *pol = novi_poligon(niz_x, niz_y, n);
    struct Tocka **toc = pozitivni(pol, &np);
    int i;
    for (i = 0; i < np; i++)
    {
        printf("%g %g\n", toc[i] -> x, toc[i] -> y);
    }
}