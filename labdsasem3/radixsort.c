#include <stdio.h>
#include <stdlib.h>

// Node definition for the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to insert a new node at the end of the linked list
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

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to perform counting sort on the linked list
void countingSort(Node **head, int exp)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    int count[10] = {0};
    Node *current = *head;

    while (current != NULL)
    {
        count[(current->data / exp) % 10]++;
        current = current->next;
    }

    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        int temp = count[i];
        count[i] = total;
        total += temp;
    }

    Node *sortedList = NULL;
    current = *head;
    while (current != NULL)
    {
        int index = (current->data / exp) % 10;
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = current->data;
        newNode->next = sortedList;
        sortedList = newNode;
        current = current->next;
    }

    current = sortedList;
    while (current != NULL)
    {
        int index = (current->data / exp) % 10;
        Node *temp = current;
        current = current->next;
        temp->next = NULL;
        insert(&head[index], temp->data);
    }

    for (int i = 0; i < 10; i++)
    {
        if (sortedList == NULL)
        {
            *head = head[i];
        }
        else
        {
            current = sortedList;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = head[i];
            *head = sortedList;
        }
    }
}

// Function to perform radix sort on the linked list
void radixSort(Node **head)
{
    int max = (*head)->data;
    Node *current = *head;
    while (current != NULL)
    {
        if (current->data > max)
        {
            max = current->data;
        }
        current = current->next;
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(head, exp);
    }
}

// Function to clear the linked list
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

int main()
{
    Node *buckets[10];
    for (int i = 0; i < 10; i++)
    {
        buckets[i] = NULL;
    }

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        insert(&buckets[num % 10], num);
    }

    printf("Original Lists:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Bucket %d: ", i);
        printList(buckets[i]);
    }

    radixSort(buckets);

    printf("Sorted Lists:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Bucket %d: ", i);
        printList(buckets[i]);
        clearList(&buckets[i]);
    }

    return 0;
}
