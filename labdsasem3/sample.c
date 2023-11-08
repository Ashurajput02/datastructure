#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data1;
    int data2;
    struct node *next;
};

struct node *head1 = NULL;

struct node *head2 = NULL;

struct node *insert(struct node *head, int x, int y)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data1 = x;
    temp->data2 = y;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        struct node *temp2 = head;
        temp->next = head;
        head = temp;
        return head;
    }
}

int main()
{

    // head1 = insert(head1, 8, 9);
    // head1 = insert(head1, 4, 3);
    // head2 = insert(head2, 3, 4);
    // head2 = insert(head2, 8, 8);

    // bubblesort(head1);
    // bubblesort(head2);
    // struct node *result = add();

    int a = 4;
    int b = 2;
    int c = pow(a, b);
    printf("%d", c);
}

bubblesort(struct node *head)
{
    struct node *temp = head;
    int swap = 0;
    int n = 2;
    for (int i = 0; i < n - 1 && temp != NULL; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            if (temp->data1 < temp->next->data1)
            {
                int x = temp->data1;
                int y = temp->data2;
                temp->data1 = temp->next->data1;
                temp->data2 = temp->next->data2;
                temp->next->data1 = x;
                temp->next->data2 = y;

                swap = 1;
            }
        if (swap != NULL)
            break;
    }
}

/*
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* current1 = poly1;
    Term* current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            result = createTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            result = createTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            result = createTerm(current1->coefficient + current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }

        result->next = addTerm(result->next, result);
    }
*/

struct node *add()
{
    struct node *current1 = head1;
    struct node *current2 = head2;
    struct node *result = NULL;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data2 > current2->data2)
        {
            result = insert(result, current1->data1, current1->data2);
            current1 = current1->next;
        }
        else if (current1->data2 < current2->data2)
        {
            result = insert(result, current2->data1, current2->data2);
            current2 = current2->next;
        }
        else
        {
            int coeff_sum = current1->data1 + current2->data1;
            result = insert(result, coeff_sum, current1->data2);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        result = insert(result, current1->data1, current1->data2);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        result = insert(result, current2->data1, current2->data2);
        current2 = current2->next;
    }

    return result;
}

// void simplify(){
//     struct node *temp1=head;
//     while(temp1!=NULL){
//         struct node *temp2=temp1->next;
//         while(temp2->NULL){
//             if(temp2->data2==temp1->data2){
//                 struct node *temp3=temp2;
//                 temp1->data2=temp1->data2+temp2->data2;
//                 prev->next=temp2->next;
//                 free(temp3);
//             }
//             struct node*prev=temp2;
//             temp2=temp2->next;

//         }
//         temp1=temp1->next;

//     }
// }

void evaluate(struct node *head, int val)
{
    struct node *temp = head;
    float ans = 0.0;
    while (temp != NULL)
    {
        ans += temp->data1 * pow(val, temp->data2);
        temp = temp->next;
    }

    return ans;
}

// adding multipolynomial

struct node *add(struct node *poly1, struct node *poly2)
{
    struct node *current1 = poly1;
    struct node *current2 = poly2;
    struct node *result = NULL;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data2 > current2->data2 || (current1->data2 == current2->data2 && current1->data3 > current2->data3))
        {
            result = insert(result, current1->data1, current1->data2, current1->data3);
            current1 = current1->next;
        }
        else if (current1->data2 < current2->data2 || (current1->data2 == current2->data2 && current1->data3 < current2->data3))
        {
            result = insert(result, current2->data1, current2->data2, current2->data3);
            current2 = current2->next;
        }
        else
        {
            int coeff_sum = current1->data1 + current2->data1;
            result = insert(result, coeff_sum, current1->data2, current1->data3);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        result = insert(result, current1->data1, current1->data2, current1->data3);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        result = insert(result, current2->data1, current2->data2, current2->data3);
        current2 = current2->next;
    }

    return result;
}
