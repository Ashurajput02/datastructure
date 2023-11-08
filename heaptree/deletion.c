#include <stdio.h>
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
    int arr[] = {0, 30, 17, 20, 1, 5, 10, 15};
    int n = 7;
    for (int i = 7; i > 1; i--)
        delete (arr, i);
    for (int i = 1; i <= 7; i++)
        printf("%d ", arr[i]);
}