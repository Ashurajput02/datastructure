#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data1;
    int data2;
    struct node *link;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;
struct node *head4 = NULL;

void insert(struct node **head, int a, int b);
void bubbleSortList(struct node *head);
void printer(struct node *head);

int main()
{

    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    int n;
    int x1;
    int y1;
    int x2;
    int y2;

    printf("Enter the coefficients and powers for polynomial 1 (x, y):\n");
    int i1 = 0;
    while (i1 != 100)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &x1);
        printf("Enter the power: ");
        scanf("%d", &y1);
        insert(&head1, x1, y1);
        printf("Enter 100 to exit: ");
        scanf("%d", &i1);
    }

    printf("Enter the coefficients and powers for polynomial 2 (x, y):\n");
    int i2 = 0;
    while (i2 != 100)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &x2);
        printf("Enter the power: ");
        scanf("%d", &y2);
        insert2(&head2, x2, y2);
        printf("Enter 100 to exit: ");
        scanf("%d", &i2);
    }

    printf("The polynomial you entered is:\n");
    printer(head1);
    printer(head2);
    bubbleSortList(head1);

    bubbleSortList(head2);

    printf("The Final mulitplied product is=\n");
    multiplication();
    bubbleSortList(head4);
    printer(head4);
    printf("Addition of both the products=\n");
    addition();
    bubbleSortList(head3);
    printer(head3);
    return 0;
}

void insert(struct node **head, int a, int b)
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

    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *temp2 = *head;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void bubbleSortList(struct node *head)
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

void printer(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("(%d)", temp->data1);
        if (temp->data2 != 0)
        {
            printf("x^%d", temp->data2);
            if (temp->link != NULL)
                printf(" + ");
        }
        temp = temp->link;
    }
    printf("\n");
}

void addition()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while (temp1 != NULL || temp2 != NULL)
    {

        if (temp1->data2 == temp2->data2)
        {
            int a = temp1->data1 + temp2->data1;
            int b = temp1->data2;
            insert3(a, b);
        }
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            insert3(temp1->data1, temp1->data2);
            temp1 = temp1->link;
        }
    }

    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            insert3(temp2->data1, temp2->data2);
            temp2 = temp2->link;
        }
    }
}

void multiplication()
{
    struct node *jig = head1;
    struct node *sim = head2;

    while (jig != NULL)
    {
        while (sim != NULL)
        {
            int a = jig->data1 * sim->data1;
            int b = jig->data2 + sim->data2;
            insert4(a, b);
            sim = sim->link;
        }
        sim = head2;
        jig = jig->link;
    }
}

void printer()
{
    struct node *temp = head1;
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
