#include <stdio.h>
void countingsort_descending(int arr[], int size, int exp)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 8; i >= 0; i--) // Start from 8 to 0 (reverse order)
    {
        count[i] += count[i + 1]; // Increment in reverse order
    }

    for (int i = size - 1; i >= 0; i--) // Place elements in reverse order
    {
        output[count[(arr[i] / exp) % 10]-1] = arr[i];
         count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}




int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void radixsort(int arr[], int size)
{
    int max = getMax(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingsort_descending(arr, size, exp);
    }
}

int main()
{
    int arr[10] = {136, 487, 358, 469, 570, 247, 598, 639, 205, 609};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixsort(arr, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
