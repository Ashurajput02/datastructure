#include <stdio.h>
void heapify(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        int j = 2 * i;
        while (j <= n - 1)
        {
            if (arr[j] < arr[j + 1])
            {
                j = j + 1;
            }
            if (arr[i] < arr[j])
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
}
void delete(int arr[], int n)
{

    int temp, i, j;
    temp = arr[1];
    arr[1] = arr[n];
    arr[n] = temp;
    i = 1;
    j = 2 * i;

    while (j <= n - 1)
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
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    heapify(arr, n);
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
