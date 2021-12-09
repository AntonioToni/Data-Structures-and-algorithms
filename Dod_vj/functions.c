#include "longnumber.h"
#pragma warning(disable:4996)

// pomocna funkcija koja okrece listu znamenaka, trebati ce na vise mjesta
// jer ce se operacije uglavnom oslanjati na dodavanje u glavu liste
// ne gradi novu listu nego preuredjuje dobivenu listu
LongNumber reverse(LongNumber num)
{
	if (num == NULL)
	{
		return num;
	}
	LongNumber tren = NULL;
	LongNumber nxt = num->next;
	num->next = NULL;
	while (nxt != NULL)
	{
		tren = nxt;
		nxt = nxt->next;
		tren->next = num;
		num = tren;
	}
	return num;

}

// cita broj iz tekstualne datoteke znamenku po znamenku i gradi listu (dugi broj)
LongNumber read_longnum(char* fname)
{
    FILE* file = fopen(fname, "r");
    LongNumber array = NULL;
    while (!feof(file))
    {
        LongNumber new = (LongNumber)malloc(sizeof(Digit));
        fscanf(file, "%d", &(new -> z));
        new->next = NULL;
        if (array == NULL)
        {
            return new;
        }
        LongNumber temp = array;
		while (temp -> next != NULL) 
		{
			temp = temp -> next;
		}
        temp -> next = new;
        return array;
    }
}

// zapisuje broj u tekstualnu datoteku znamenku po znamenku
void write_longnum(LongNumber num, char* fname)
{
    FILE* file = fopen(fname, "w");
    while (num != NULL)
    {
        fprintf(file, "%d", num->z);
        printf("%d", num -> z);
        num = num -> next;
    }
}

// ispisuje broj na ekran 
void print_longnum(LongNumber num)
{
    while (num != NULL)
    {
        printf("%d", num -> z);
        num = num -> next;
    }
}

// oslobadja listu znamenaka
void delete_longnum(LongNumber num)
{
   	while (num != NULL) 
	{
		LongNumber temp = num;
		num = num->next;
		free(temp);
	} 
}

// zbraja dva broja. 
// Algoritam zbraja znamenku po znamenku i prenosi ostatak na iducu znamenku.
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber add_longnum(LongNumber a, LongNumber b)
{
	if (a->z == 0)
    {
		return b;
    }
    if (b->z == 0)
	{
    	return a;
    }
    LongNumber n1 = a;
    LongNumber n2 = b;
    LongNumber c = NULL;
    int extra = 0, sum = 0;
    while (n1 || n2)
    {
        sum = 0;
        if (n1)
        {
            sum += n1 ->z;
        }
        if (n2)
        {
            sum += n2 -> z;
        }
        sum += extra;
        extra = sum /10;
        sum = sum % 10;
        LongNumber new = (LongNumber)malloc(sizeof(Digit)); ////
        new -> z = sum; ////
        new -> next = c; ////
        if (n1)
        {
            n1 = n1 -> next;
        }
        if (n2)
        {
            n2 = n2 -> next;
        }
    }
    if (extra)
    {
        LongNumber new = (LongNumber)malloc(sizeof(Digit)); ////
        new -> z = sum; ////
        new -> next = c; ////
    }
    return c;
}

// pomocna funkcija koja mnozi broj sa znamenkom (uz prenosenje ostatka na iducu znamenku). 
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_digit(LongNumber num, int z)
{
    LongNumber n1 = num;
    LongNumber e = NULL;
    int extra = 0, res;
    while (n1)
    {
        res = 1;
        if (n1)
        {
            res += extra + (n1 -> z)*z;
        }
        extra = res / 10;
        res = res % 10;
        LongNumber new = (LongNumber)malloc(sizeof(Digit)); ////
        new -> z = res; ////
        new -> next = e; ////
        if (n1)
        {
            n1 = n1 -> next;
        }
    }
    if (extra != 0)
    {
        LongNumber new = (LongNumber)malloc(sizeof(Digit)); ////
        new -> z = res; ////
        new -> next = e; ////
    }
    return e;
}

// pomocna funkcija koja mnozi broj sa potencijom od 10 (odnosno dodaje nule na pocetak broja)
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_pow10(LongNumber num, int pow);