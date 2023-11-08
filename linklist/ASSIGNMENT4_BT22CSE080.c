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

struct node *reverse(struct node *head)
{
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL)
    {
        int data = current->data;
        int reversedData = 0;

        // Reverse the digits
        while (data != 0)
        {
            int digit = data % 10;
            reversedData = reversedData * 10 + digit;
            data = data / 10;
        }

        // Update the data in the current node
        current->data = reversedData;

        // Move to the next node
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
    while (temp1 != NULL || temp2 != NULL || carry)
    {
        int sum = carry;

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
        printf("%04d", temp->data); // Print with leading zeros
        temp = temp->next;
    }
}

int main()
{
    printf("enter the first number\n");
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        head1 = insert(head1, n % 10000);
        n = n / 10000;
    }

    printf("enter the second number\n");
    int k;
    scanf("%d", &k);
    while (k != 0)
    {
        head2 = insert(head2, k % 10000);
        k = k / 10000;
    }

    printf("\n");
    head1 = reverse(head1);

    head2 = reverse(head2);
    sum();
    printf("Sum: ");
    head3 = reverse(head3);
    printer(head3);

    // Free memory
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
