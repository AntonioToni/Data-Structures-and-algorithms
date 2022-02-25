#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next; 
} Array;

void print(Array* arr) //print array
{
    printf("\n[ ");
    while (arr!=NULL)
    {
        if (arr->next==NULL)
        {
            printf("%d ]\n", arr->num);
        }
        else
        {
            printf("%d, ", arr->num);
        }
        arr = arr->next;
    }
}

Array* insertFirst(Array* arr, int x)
{
    Array* tmp = (Array*)malloc(sizeof(Array));
    tmp->num=x;
    tmp->next=arr;
    arr=tmp;
    return arr;
}

int checkarr(Array* arr1, Array* arr2)
{
    Array* tmp1 = arr1;
    Array* tmp2 = arr2;
    while (tmp1 != NULL)
    {
        while (tmp2 != NULL)
        {
            printf("%d %d\n", tmp1->num, tmp2->num);
            if (tmp1->num == tmp2->num)
            {
                break;
            }
            else if (tmp2->next==NULL)
            {
                return 0;
            }
            
            else
            {
                tmp2=tmp2->next;
            }
        }
        tmp1=tmp1->next;
        tmp2=arr2;
    }
    return 1;
}

Array* delFirstLast(Array* arr1)
{
    if(arr1==NULL)
    {
        return;
    }
    Array* tmp;
    tmp = arr1;
    arr1 = arr1->next;
    free(tmp);
    if (arr1==NULL)
    {
        return;
    }
    if (arr1->next == NULL)
    {
        tmp = arr1;
        arr1 = arr1->next;
        free(tmp);
        return arr1;
    }
    tmp=arr1;
    while (tmp->next->next!=NULL)
    {
        tmp=tmp->next;
    }
    free(tmp->next);
    tmp->next=NULL;
    return arr1;
}

int main()
{
    //construct arr1 4 3 2
    Array* arr1 = (Array*)malloc(sizeof(Array));
    arr1->num=2;
    arr1->next = NULL;
    arr1 = insertFirst(arr1, 3);
    arr1 = insertFirst(arr1, 4);
    print(arr1);
    //construct arr2 2 1 4
    Array* arr2 = (Array*)malloc(sizeof(Array));
    arr2->num=4;
    arr2->next = NULL;
    arr2 = insertFirst(arr2, 3);
    arr2 = insertFirst(arr2, 2);
    arr2 = insertFirst(arr2, 6);
    print(arr2);
    printf("%d", checkarr(arr1,arr2));
    arr1 = delFirstLast(arr1);
    print(arr1);
}