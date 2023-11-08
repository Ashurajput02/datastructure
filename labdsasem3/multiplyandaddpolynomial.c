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

struct node *head1;
struct node *head2;
struct node *head3;
struct node *head4;

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
        insert(x1, y1);
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
        insert2(x2, y2);
        printf("Enter 100 to exit: ");
        scanf("%d", &i2);
    }

    printf("The polynomial you entered is:\n");
    printer();
    printer2();
    bubbleSortList();

    bubbleSortList2();

    printf("The Final mulitplied product is=\n");
    multiplication();
    bubbleSortList4();
    printer4();
    // printf("Addition of both the products=\n");
    // addition();
    // bubbleSortList3();
    // printer3();

    // simplify(&head4);
    printer4();

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

    if (head1 == NULL)
    {
        head1 = temp;
        return;
    }
    else
    {
        struct node *temp2 = head1;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void insert3(int a, int b)
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

    if (head3 == NULL)
    {
        head3 = temp;
        return;
    }
    else
    {
        struct node *temp2 = head3;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void insert2(int a, int b)
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

    if (head2 == NULL)
    {
        head2 = temp;
        return;
    }
    else
    {
        struct node *temp2 = head2;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
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
void printer2()
{
    struct node *temp = head2;
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

void printer3()
{
    struct node *temp = head3;
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

void bubbleSortList2()
{
    int swapped, template1, template2;
    struct node *temp;
    struct node *ptr = NULL;

    if (head2 == NULL)
        return;

    do
    {
        swapped = 0;
        temp = head2;

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

void bubbleSortList3()
{
    int swapped, template1, template2;
    struct node *temp;
    struct node *ptr = NULL;

    if (head3 == NULL)
        return;

    do
    {
        swapped = 0;
        temp = head3;

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

struct node *findTermWithExponent(struct node *head, int exponent)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data2 == exponent)
        {
            return current; // Found a term with the specified exponent
        }
        current = current->link;
    }
    return NULL; // No term with the specified exponent found
}

void multiplication()
{
    struct node *jig = head1;
    struct node *sim = head2;
    struct node *result = NULL; // Initialize the result linked list

    while (jig != NULL)
    {
        while (sim != NULL)
        {
            int a = jig->data1 * sim->data1;
            int b = jig->data2 + sim->data2;

            // Find a term with the same exponent 'b' in the result list
            struct node *existingTerm = findTermWithExponent(result, b);

            if (existingTerm != NULL)
            {
                existingTerm->data1 += a; // Combine coefficients of like terms
            }
            else if (a != 0) // Add the term if coefficient is non-zero
            {
                insert4(a, b);
            }

            sim = sim->link;
        }
        sim = head2;
        jig = jig->link;
    }

 head4=result;// Update the global result list
}

// void multiplication()
// {
//     struct node *jig = head1;
//     struct node *sim = head2;

//     while (jig != NULL)
//     {
//         while (sim != NULL)
//         {
//             int a = jig->data1 * sim->data1;
//             int b = jig->data2 + sim->data2;
//             insert4(a, b);
//             sim = sim->link;
//         }
//         sim = head2;
//         jig = jig->link;
//     }
// }

void insert4(int a, int b)
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

    if (head4 == NULL)
    {
        head4 = temp;
        return;
    }
    else
    {
        struct node *temp2 = head4;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void bubbleSortList4()
{
    int swapped, template1, template2;
    struct node *temp;
    struct node *ptr = NULL;

    if (head4 == NULL)
        return;

    do
    {
        swapped = 0;
        temp = head4;

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

void printer4()
{
    struct node *temp = head4;
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

// void simplify(struct node **head)
// {
//     struct node *current = *head;
//     struct node *prev = NULL;

//     while (current != NULL && current->link != NULL)
//     {
//         if (current->data2 == current->link->data2)
//         {
//             current->data1 += current->link->data1;
//             struct node *temp = current->link;
//             current->link = temp->link;
//             free(temp);
//         }
//         else if (current->data1 == 0)
//         {
//             if (prev == NULL)
//                 *head = current->link;

//             else
//                 prev->link = current->link;
//             struct node *temp = current;
//             current = current->link;
//             free(temp);
//         }
//         else
//         {
//             prev = current;
//             current = current->link;
//         }
//     }
// }
