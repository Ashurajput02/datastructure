
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
int main()
{
    enque(5, 2);
    enque(6, 3);
    enque(7, 1);
    enque(8, 2);
    enque(2, 4);

    display();
    // dequeue();

    // dequeue();
    // dequeue();
    // display();
    // dequeue();
    // display();
}
void enque(int x, int priority)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->priority = priority; // Set the priority
    temp->next = NULL;

    if (isempty())
    {
        front = temp;
        rear = temp;
    }
    else if (isfull())
    {
        printf("queue overflow\n");
        return;
    }
    else
    {
        if (priority < front->priority)
        { // Check if new element has higher priority
            temp->next = front;
            front = temp;
        }
        else
        {
            struct node *curr = front;
            while (curr->next != NULL && curr->next->priority <= priority)
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }
}

void dequeue()
{
    if (isempty())
    {
        printf("nothing to dequeue\n");
        return;
    }

    else
    {
        struct node *temp2 = front;
        front = front->next;
        free(temp2);
    }
}

void display()
{

    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}

int isempty()
{

    if (front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}
int isfull()
{

    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    if (temp2 == NULL)
        return 1;
    else
        return 0;
}
