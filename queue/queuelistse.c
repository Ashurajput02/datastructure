#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
int main()
{
    enque(5);
    enque(6);
    enque(7);
    enque(8);
    enque(2);
    enque(1);
    display();
    dequeue();

    dequeue();
    dequeue();
    display();
    enque(77);
    display();
    dequeue();
    display();
}

void enque(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
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
        rear->next = temp;
        rear = temp;
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
        printf("%d", temp->data);
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
