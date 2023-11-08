#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct Node *addLongIntegers(struct Node *num1, struct Node *num2)
{
    struct Node *result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0)
    {
        int sum = carry;
        if (num1 != NULL)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL)
        {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum %= 10;

        insertNode(&result, sum);
    }

    return reverseList(result);
}

void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *num1 = NULL;
    struct Node *num2 = NULL;
    printf("Enter the first long integer (enter -1 to stop): ");
    int data;
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        insertNode(&num1, data);
    }

    printf("Enter the second long integer (enter -1 to stop): ");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        insertNode(&num2, data);
    }

    struct Node *result = addLongIntegers(num1, num2);
    printf("Result: ");
    displayList(result);

    while (num1 != NULL)
    {
        struct Node *temp = num1;
        num1 = num1->next;
        free(temp);
    }

    while (num2 != NULL)
    {
        struct Node *temp = num2;
        num2 = num2->next;
        free(temp);
    }

    while (result != NULL)
    {
        struct Node *temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
