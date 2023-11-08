#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1;
struct node *head2;
struct node *head3 = NULL;

struct node *insert(struct node *head, int x)
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
// }
// struct node *reverse(struct node *head)
// {
//     struct node *temp = head;
//     while (temp != NULL)
//     {
//         int data = head->data;
//         int res = 0;
//         while (data != 0)
//         {
//             int s = data % 10;
//             res = res + s * 10;
//             data = data / 10;
//         }
//         temp->data = res;
//         temp = temp->next;
//     }
// }

struct node *reverse(struct node *head)
{
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL)
    {
        int data = current->data;
        int reversedData = 0;

        while (data != 0)
        {
            int digit = data % 10;
            reversedData = reversedData * 10 + digit;
            data = data / 10;
        }

        current->data = reversedData;

        prev = current;
        current = current->next;
    }

    return head;
}

void sum()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int sum = 0;

        if (temp1)
            sum = sum + head1->data;

        if (temp2)
            sum = sum + head2->data;
        sum = sum + carry;
        carry = sum % 10000;
        sum = sum / 10000;
        head3 = insert(head3, (sum));
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            sum = sum + head1->data + carry;
            carry = sum % 10000;
            sum = sum / 10000;
            head3 = insert(head3, (sum));
            temp1 = head1->next;
        }
    }
    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            sum = sum + head2->data + carry;
            carry = sum % 10000;
            sum = sum / 10000;
            head3 = insert(head3, (sum));

            temp2 = head2->next;
        }
    }
}
void printer(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    printf("enter the number\n");

    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        head1 = insert(head1, n % 10000);
        n = n / 10000;
    }
    printf("enter second number\n");
    int k;
    scanf("%d", &k);
    while (k != 0)
    {
        head2 = insert(head2, k % 10000);
        k = k / 10000;
    }
    printer(head1);
    head1 = reverse(head1);
    printf("\n");
    printer(head1);
    printf("\n");
    head2 = reverse(head2);
    printer(head1);
    printf("\n");
    printer(head2);
    sum();
}
