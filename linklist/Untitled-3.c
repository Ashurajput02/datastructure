#include <stdio.h>
#include <stdlib.h>

void insert(int a, int b);
void printer();
void bubbleSortList();

struct node
{
    int data1;
    int data2;
    struct node *link;
};

struct node *head;

int main()
{
    head = NULL;
    int n;
    int x;
    int y;

    printf("Enter the coefficients and powers (x, y):\n");
    int i = 0;
    while (i != 100)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &x);
        printf("Enter the power: ");
        scanf("%d", &y);
        insert(x, y);
        printf("Enter 100 to exit: ");
        scanf("%d", &i);
    }

    printf("The polynomial in standard format is:\n");
    printer();
    bubbleSortList();

    printf("Polynomial in standard format is:\n");
    printer();

    return 0;
}

void insert(int a, int b)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory overflow!\n");
        exit(EXIT_FAILURE);
    }

    temp->data1 = a;
    temp->data2 = b;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        struct node *temp2 = head;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void printer()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("(%d)", temp->data1);
        if (temp->data2 == 0)
        {
        }
        else
        {
            printf("x^%d", temp->data2);
            if (temp->link != NULL)
                printf(" + ");
        }
        temp = temp->link;
    }
    printf("\n");
}

void bubbleSortList()
{
    int swapped, template1, template2;
    struct node *temp;
    struct node *ptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        temp = head;

        while (temp->link != ptr)
        {
            if (temp->data2 < temp->link->data2)
            {
                template1 = temp->data1;
                template2 = temp->data2;
                temp->data1 = temp->link->data1;
                temp->data2 = temp->link->data2;
                temp->link->data1 = template1;
                temp->link->data2 = template2;
                swapped = 1;
            }
            temp = temp->link;
        }
        ptr = temp;
    } while (swapped);
}
