#include <stdio.h>

typedef struct
{
    void *x;
    int priority;
}PriorityQueue;

void fixup(PriorityQueue *array, int c)
{
    int x;
    int r = (c-1) / 2;
    if (array[r].priority < array[c].priority)
    {
        x = array[r].priority;
        array[r].priority = array[c].priority;
        array[c].priority = x;
        fixup(array, r);
    }
}

void fixdown(PriorityQueue *array, int r)
{
    int x;
    int l = 2 * r + 1;
    int d = 2 * r + 2;
    if (array[r].priority < array[l].priority && array[r].priority < array[d].priority)
    {
        if (array[l].priority > array[d].priority)
        {
            x = array[r].priority;
            array[r].priority = array[l].priority;
            array[l].priority = x;
            fixdown(array, l);
        }
        else
        {
            x = array[r].priority;
            array[r].priority = array[d].priority;
            array[d].priority = x;
            fixdown(array, d);
        }
    }
}

int add(PriorityQueue *array, int *i, int el)
{
    array[*i].priority = el;
    fixup(array, (*i));
    (*i)++;
}

int delete(PriorityQueue *array, int*i)
{
    array[0].priority = array[(*i) - 1].priority;
    array[(*i) - 1].priority = 0;
    fixdown(array, 0);
    (*i)--;
}

void print(PriorityQueue *array, int i)
{
    int j;
    for (j = 0; j < i; j++)
	{
		printf("%d ", array[j].priority);
	}
	printf("\n");
}

int main()
{
    PriorityQueue array[10000];
    int i = 0;
    add(array, &i, 10);
    add(array, &i, 30);
    add(array, &i, 20);
    add(array, &i, 15);
    add(array, &i, 25);
    add(array, &i, 45);
    add(array, &i, 40);
    add(array, &i, 5);
    print(array, i);
    delete(array, &i);
    print(array, i);
}