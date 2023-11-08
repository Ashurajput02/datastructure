#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int head[11];
void heapify(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        if (i == 1)
        {
            if (arr[0] > arr[1])
            {
                swap(&arr[1], &arr[0]);
                continue;
            }
        }
        if (i & 1)
        {
            if (arr[i] < arr[(i - 2) / 2])
            {
                swap(&arr[i], &arr[(i - 2) / 2]);
            }
        }
        else
        {
            if (arr[i] < arr[(i - 1) / 2])
            {
                swap(&arr[i], &arr[(i - 1) / 2]);
            }
        }
    }
}

void deleteMin(int arr[], int n)
{
    int last = arr[n - 1];
    arr[0] = last;
    n = n - 1;
    heapifyMax(arr, n);
}

void fun(int arr[], int n, int final[])
{
    int last = arr[n - 1];
    final[n - 1] = arr[0];
    arr[n - 1] = arr[0];
    arr[0] = last;
    n = n - 1;
    heapifyMax(arr, n);
}

void heapsort(int arr[], int n)
{
    if (n == 0)
    {

        return;
    }
    int final[n];

    fun(arr, n, final);
    n = n - 1;
    heapsort(arr, n);
}

void heapifyMax(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        if (i == 1)
        {
            if (arr[0] < arr[1])
            {
                swap(&arr[1], &arr[0]);
                continue;
            }
        }
        if (i & 1)
        {
            if (arr[i] > arr[(i - 2) / 2])
            {
                swap(&arr[i], &arr[(i - 2) / 2]);
            }
        }
        else
        {
            if (arr[i] > arr[(i - 1) / 2])
            {
                swap(&arr[i], &arr[(i - 1) / 2]);
            }
        }
    }
}

int main()
{

    // printf("enter the 10 elements of the heap\n");
    // for(int i=0;i<10;i++){
    //  scanf("%d",head[i]);
    // }

    int head[7] = {3, 5, 6, 8, 9, 7, 1};
   // heapify(head, 7);
     heapifyMax(head, 7);
    printf("termination\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", head[i]);
    }
    printf("\n");
     deleteMin(head,7);

    for(int i=0;i<6;i++){
     printf("%d ",head[i]);
    }
printf("\n");

    // heapsort(head, 7);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", head[i]);
    }
}