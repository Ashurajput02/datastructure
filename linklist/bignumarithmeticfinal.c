#include <stdio.h>
#include <stdlib.h>

struct node
{
    long long int data;
    struct node *next;
};

struct node *head1;
struct node *head2;
struct node *head3 = NULL;

struct node *insert(struct node *head, long long int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else if (head != NULL)
    {
        struct node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        return head;
    }
}

void sum()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    long long int carry = 0;
    while (temp1 != NULL || temp2 != NULL || carry)
    {
        long long int sum = carry;

        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10000;
        sum = sum % 10000;
        head3 = insert(head3, sum);
    }
    if (carry > 0)
        head3 = insert(head3, carry);
}

void printer(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%04lld", temp->data);
        temp = temp->next;
    }
}

struct node *reverse(struct node *head)
{
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL)
    {
        long long int data = current->data;
        long long int reversedData = 0;

        while (data != 0)
        {
            long long int digit = data % 10;
            reversedData = reversedData * 10 + digit;
            data = data / 10;
        }

        current->data = reversedData;

        prev = current;
        current = current->next;
    }

    return head;
}

void reverser()
{
    struct node *curr = head3;
    struct node *prev = NULL;
    struct node *link = NULL;

    while (curr != NULL)
    {
        link = curr->next;
        curr->next = prev;
        prev = curr;
        curr = link;
    }

    head3 = prev;
}
int main()
{
    printf("enter the first number\n");
    long long int n;
    scanf("%lld", &n);
    while (n != 0)
    {
        head1 = insert(head1, n % 10000);
        n = n / 10000;
    }

    printf("enter the second number\n");
    long long int k;
    scanf("%lld", &k);
    while (k != 0)
    {
        head2 = insert(head2, k % 10000);
        k = k / 10000;
    }

    printf("\n");
    sum();
    printf("Sum in reverse: ");
    printer(head3);
    printf("\n");
    reverser();
    printf("sum originally:");
    printer(head3);

    printf("\n");

    while (head1 != NULL)
    {
        struct node *temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL)
    {
        struct node *temp = head2;
        head2 = head2->next;
        free(temp);
    }
    while (head3 != NULL)
    {
        struct node *temp = head3;
        head3 = head3->next;
        free(temp);
    }

    return 0;
}
