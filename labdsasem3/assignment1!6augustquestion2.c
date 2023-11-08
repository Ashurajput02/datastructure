

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data1;
    int data2;
    struct node *link;
};

struct node *head1;

void insert(int a, int b);
void adder(int x, int y);
void bubbleSortList();

int main()
{
    head1 = NULL;
    int x1, y1;
    printf("Enter the coefficients and powers for polynomial 1 (x, y):\n");
    int i1 = 0;
    while (i1 != 100)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &x1);
        printf("Enter the power: ");
        scanf("%d", &y1);
        insert(x1, y1);
        printf("Enter 100 to exit: ");
        scanf("%d", &i1);
        if (i1 == 100)
            break;
    }

    int x2, y2;
    printf("Enter the coefficients and powers for polynomial 2 (x, y):\n");
    int i2 = 0;
    while (i2 != 100)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &x2);
        printf("Enter the power: ");
        scanf("%d", &y2);
        adder(x2, y2);
        printf("Enter 100 to exit: ");
        scanf("%d", &i2);
        if (i2 == 100)
            break;
    }

    bubbleSortList();
    printf("The final polynomial on addition =\n");
    struct node *tashu = head1;
    while (tashu != NULL)
    {
        printf("%d x^%d", tashu->data1, tashu->data2);
        if (tashu->link != NULL)
            printf(" + ");
        tashu = tashu->link;
    }

    tashu = head1;
    while (tashu != NULL)
    {
        struct node *temp = tashu;
        tashu = tashu->link;
        free(temp);
    }

    return 0;
}

void adder(int x, int y)
{
    int flag = 0;

    struct node *temp = head1;
    while (temp != NULL)
    {
        if (temp->data2 == y)
        {
            flag = 1;
            break;
        }
        temp = temp->link;
    }
    if (flag == 1)
    {
        temp->data1 += x;
    }
    else
    {
        insert(x, y);
    }
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

    if (head1 == NULL)
    {
        head1 = temp;
    }
    else
    {
        struct node *temp2 = head1;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void bubbleSortList()
{
    int swapped, template1, template2;
    struct node *temp;
    struct node *ptr = NULL;

    if (head1 == NULL)
        return;

    do
    {
        swapped = 0;
        temp = head1;

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
