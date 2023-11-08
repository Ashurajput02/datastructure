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

void delete(int arr[], int n)
{

    int temp, i, j;
    temp = arr[1];
    arr[1] = arr[n];
    arr[n] = temp;
    i = 1;
    j = 2 * i;

    while (j < n - 1)
    {

        if (arr[j] < arr[j + 1])
            j = j + 1;
        if (arr[j] > arr[i])
        {
            int amp = arr[i];
            arr[i] = arr[j];
            arr[j] = amp;
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}

int main()
{
    int arr[8] = {0, 10, 20, 30, 25, 5, 40, 35};
    int n = 7;
    for (int i = 2; i <= n; i++)
    {
        insert(arr, i);
    }
    printf("after insrtion in max heap tree\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    for (int i = n; i >= 1; i--)
        delete (arr, i);
    printf("after heap sort \n");

    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    return 0;
}
