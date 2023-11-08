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
    int n;
    printf("enter the size of the array\n");
    scanf("%d", &n);
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        insert(arr, i);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = n; i > 1; i--)
        delete (arr, i);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}