#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void clearList(Node **head)
{
    Node *current = *head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void radixSort(int arr[], int n)
{ // first loop to calculate the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // loop to calc no. of digits in maximum element
    int digits = 0;
    while (max > 0)
    {
        digits++;
        max /= 10;
    }
    // loop to put the elements in bins based on the value which came on exp calcn.
    for (int exp = 1; digits > 0; exp *= 10, digits--)
    {
        Node *buckets[10] = {NULL};

        for (int i = 0; i < n; i++)
        {
            int index = (arr[i] / exp) % 10;
            insert(&buckets[index], arr[i]);
        }
        // iss loop se kya hai mein jo bin mein value aayi hai jis order main main uss order wise hi array
        // mein values put karte jaa rha hoon aur bin ki memory ko free bhi karte jaa rha hoon.

        printf("Sorted Array (Phase %d): ", exp);
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            Node *current = buckets[i];
            while (current != NULL)
            {
                arr[index++] = current->data;
                Node *temp = current;
                current = current->next;
                free(temp);
            }
        }
        // yeh loop har phase ke baad array ko print kar rha hai
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("Final Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    return 0;
}

/*in this code you separetely need no to use clear list funxction as loop ke dauran hi memory deallocate kara di jaa rhi hai. */

// void radixSortDescending(int arr[], int n)
// {
//     int max = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }

//     int digits = 0;
//     while (max > 0)
//     {
//         digits++;
//         max /= 10;
//     }

//     for (int exp = 1; digits > 0; exp *= 10, digits--)
//     {
//         Node *buckets[10] = {NULL};

//         for (int i = 0; i < n; i++)
//         {
//             int index = 9 - (arr[i] / exp) % 10; // Change here: Reverse the index
//             insert(&buckets[index], arr[i]);
//         }

//         int index = 0;
//         for (int i = 9; i >= 0; i--) // Change here: Iterate in reverse order
//         {
//             Node *current = buckets[i];
//             while (current != NULL)
//             {
//                 arr[index++] = current->data;
//                 Node *temp = current;
//                 current = current->next;
//                 free(temp);
//             }
//         }
//     }

//     printf("Sorted Array (Descending Order): ");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }