#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
    int additional;
	struct node *next; 
} Array;

void func(Array* arr) //Insert 0 between two even numbers
{
    while (arr->next!=NULL)
    {
        if(arr->num % 2 == 0 && arr->next->num % 2 == 0 && arr->num!=0 &&arr->next!=0)
        {
			Array* tmp1 = (Array*)malloc(sizeof(Array));
            tmp1->num = 0;
            tmp1->next = arr->next;
            arr->next = tmp1;
        }
        arr = arr->next;
    }
}

Array* returnpointer(Array* arr, int x)
{
    Array *tmp = malloc(sizeof(Array));
    while (arr != NULL)
    {
        if (arr->num > x)
        {
            tmp = arr;
        }
        arr = arr->next;
    }
    if (tmp!=NULL)
    {
        return tmp->num;
    }
    return NULL;
}

Array* deletenode(Array* arr)
{

    if (arr->num%arr->additional==0)
    {
        Array* tmp = arr;
        arr = arr->next;
        free(tmp);
        return;
    }
    arr= arr->next;
    deletenode(arr->next);
}

void print(Array* arr) //print array
{
    printf("\n[ ");
    while (arr!=NULL)
    {
        if (arr->next==NULL)
        {
            printf("%d ]", arr->num);
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

Array* insertFirstaddit(Array* arr, int x, int y)
{
    Array* tmp = (Array*)malloc(sizeof(Array));
    tmp->num=x;
    tmp->additional=y;
    tmp->next=arr;
    arr=tmp;
    return arr;
}

Array* merge(Array* arr1, Array* arr2)
{
    Array* tmp = arr1;
    Array* new = (Array*)malloc(sizeof(Array));
    while (tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    new = arr2;
    new->next=NULL;
    tmp->next = new;
    return arr1;

}

int main()
{
    Array* arr = (Array*)malloc(sizeof(Array));
    Array* tmp = (Array*)malloc(sizeof(Array));
    arr->num=2;
    arr->additional=1;

    tmp->num=2;
    tmp->next=NULL;

    arr->next=tmp;

    arr = insertFirst(arr,2);
    arr = insertFirst(arr,3);
    print(arr);
    //Add 0 between two equal numbers
    func(arr);
    print(arr);
    //////////////////////////////////
    Array* arrpoi = (Array*)malloc(sizeof(Array));
    arrpoi->next=NULL;
    arrpoi->num=1;
    arrpoi->additional=6;
    arrpoi = insertFirstaddit(arrpoi, 2, 3);
    arrpoi = insertFirstaddit(arrpoi, 5, 4);
    arrpoi = insertFirstaddit(arrpoi, 2, 2);
    arrpoi = insertFirstaddit(arrpoi, 1, 1);
    print(arrpoi);
    printf("\n%d", returnpointer(arrpoi));
    ////////////////
    Array* arr3 = (Array*)malloc(sizeof(Array));
    arr3 = merge(arr,arrpoi);
    print(arr3);
    //////////
    Array* arr4 = (Array*)malloc(sizeof(Array));
    arr4 = deletenode(arrpoi);
    print(arr4);
}