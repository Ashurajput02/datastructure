#include <stdio.h>

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

    int arr[8] = {0, 5, 10, 30, 20, 35, 40, 15};
    int n = 7;
    heapify(arr, n);
    printf("after insertion using heapify method\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n after applying heap sort:\n");
    for (int i = n; i >= 1; i--)
    {
        delete (arr, i);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
