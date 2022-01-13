#include <stdio.h>
#include <conio.h>

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

int add()
{

}

int remove()
{

}

int main()
{
    
}