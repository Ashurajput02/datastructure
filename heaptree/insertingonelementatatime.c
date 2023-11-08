#include <stdio.h>
void insert(int arr[], int n)
{
    int temp, i;
    i = n;
    temp = arr[i];
    while (i > 1 && temp > arr[i / 2])
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = temp;
}

int main()
{
    int arr[8] = {0, 10, 20, 30, 25, 5, 40, 35};
    int n = 7;
    for (int i = 2; i <= n; i++)
    {
        insert(arr, i);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}
