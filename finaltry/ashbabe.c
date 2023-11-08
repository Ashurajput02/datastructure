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

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2); i >= 1; i--)
    {

        int j = 2 * i; // Left child for current i

        while (j <= n)
        {
            // Compare left and right children of current i
            if (A[j] < A[j + 1])
            {
                j = j + 1;
            }

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i;
            }
            else
            {
                break;
            }
        }
    }
}

// int main()
// {

//     int arr[8] = {0, 15, 5, 30, 1, 17, 10, 20};
//     int n = 7;
//     heapify(arr, n);
//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d ", arr[i]);
//     }

// printf("\n");
//      for (int i = 7; i > 1; i--)
//         delete (arr, i);
//     for (int i = 1; i <= 7; i++)
//         printf("%d ", arr[i]);

//     return 0;
// }

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
    return 0;
}