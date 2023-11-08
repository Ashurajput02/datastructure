#include <stdio.h>
#include <stdlib.h>
void insert(int a, int b);
void printer();
struct node
{
    int data1;
    int data2;
    struct node *link;
};
struct node *head;

int main()
{

    head = NULL; // suggests the list is empty so far

    int n;
    int x;
    int y;

    scanf("%d", &n);
    int i = 0;
    while (i != 100)
    {
        printf("enter the coefficient\n");
        scanf("%d", &x);
        printf("enter the power\n");
        scanf("%d", &y);
        insert(x, y);
        printf("enter 100 to exit\n");
        scanf("%d", &i);
    }
    printer();
    printf("the polynomial in standard format is=");
    bubbleSortList();
    printer();
    return 0;
}

void insert(int a, int b)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node)); // most imp
    temp->data1 = a;
    temp->data2 = b;
    temp->link = NULL;
    struct node *temp2 = head;
    if (head == NULL)
    {
        head = temp;
        return;
    }

    else
    {
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void printer()
{
    struct node *temp = head;
    printf("final polynomial is:\n");
    while (temp != NULL)
    {
        printf("( %d )", temp->data1);
        if (temp->data2 == 0)
        {
        }

        else
        {
            printf("x^ ");

            printf("%d", temp->data2);
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
            if (temp->data2 > temp->link->data2)
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
