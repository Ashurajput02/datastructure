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

int main()
{

    int arr[8] = {0, 15, 5, 30, 1, 17, 10, 20};
    int n = 7;
    heapify(arr, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
