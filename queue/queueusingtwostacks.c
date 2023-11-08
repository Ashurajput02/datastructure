// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// };
// void push(struct node** top, int data);
// int pop(struct node** top);
// struct queue
// {
//     struct node *stack1;
//     struct node *stack2;
// };
// void enqueue(struct queue *q, int x)
// {
//     push(&q->stack1, x);
// }
// void dequeue(struct queue *q)
// {
//     int x;
//     if (q->stack1 == NULL && q->stack2 == NULL) {
//         printf("queue is empty");
//         return;
//     }
//     if (q->stack2 == NULL) {
//         while (q->stack1 != NULL) {
//         x = pop(&q->stack1);
//         push(&q->stack2, x);
//         }
//     }
//     x = pop(&q->stack2);
//     printf("%d\n", x);
// }
// void push(struct node** top, int data)
// {
//     struct node* newnode = (struct node*) malloc(sizeof(struct node));
//         if (newnode == NULL) {
//             printf("Stack overflow \n");
//             return;
//         }
//     newnode->data = data;
//     newnode->next = (*top);
//     (*top) = newnode;
// }
// int pop(struct node** top)
// {
//     int buff;
//     struct node *t;
//     if (*top == NULL) {
//         printf("Stack underflow \n");
//         return;
//     }
//     else {
//         t = *top;
//         buff = t->data;
//         *top = t->next;
//         free(t);
//         return buff;
//     }
// }
// // void display(struct node *top1,struct node *top2)
// // {
// //     while (top1 != NULL) {
// //         printf("%d\n", top1->data);
// //         top1 = top1->next;
// //     }
// //     while (top2 != NULL) {
// //         printf("%d\n", top2->data);
// //         top2 = top2->next;
// //     }
// // }

// void display(struct node* top1, struct node* top2)
// {
//     if (top1 == NULL && top2 == NULL) {
//         printf("Queue is empty.\n");
//         return;
//     }

//     printf("Elements in the queue:\n");

//     // Print elements of stack1
//     while (top1 != NULL) {
//         printf("%d\n", top1->data);
//         top1 = top1->next;
//     }

//     // Print elements of stack2 in reverse order
//     struct node* temp = top2;
//     while (temp != NULL) {
//         printf("%d\n", temp->data);
//         temp = temp->next;
//     }
// }

// int main()
// {
//     struct queue *q = (struct queue*)malloc(sizeof(struct queue));
//     int f = 0, a;
//     char ch = 'y';
//     q->stack1 = NULL;
//     q->stack2 = NULL;
//     while (ch == 'y'||ch == 'Y') {
//         printf("enter ur choice\n1.add to queue\n2.remove 
//                from queue\n3.display\n4.exit\n");
//         scanf("%d", &f);
//         switch(f) {
//             case 1 : printf("enter the element to be added to queue\n");
//                      scanf("%d", &a);
//                      enqueue(q, a);
//                      break;
//             case 2 : dequeue(q);
//                      break;
//             case 3 : display(q->stack1, q->stack2);
//                      break;
//             case 4 : exit(1);
//                      break;
//             default : printf("invalid\n");
//                       break;
//         }
//     }

//     free(q);
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void push(struct node** top, int data);
int pop(struct node** top);

struct queue
{
    struct node* stack1;
    struct node* stack2;
};

void enqueue(struct queue* q, int x)
{
    push(&q->stack1, x);
}

void dequeue(struct queue* q)
{
    int x;
    if (q->stack1 == NULL && q->stack2 == NULL) {
        printf("Queue is empty\n");
        return;
    }
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
            x = pop(&q->stack1);
            push(&q->stack2, x);
        }
    }
    x = pop(&q->stack2);
    printf("%d\n", x);
}

void push(struct node** top, int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node** top)
{
    int buff;
    struct node* t;
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1; // Return a default value or handle underflow condition
    }
    else {
        t = *top;
        buff = t->data;
        *top = t->next;
        free(t);
        return buff;
    }
}

void display(struct node* top1, struct node* top2)
{
    if (top1 == NULL && top2 == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue:\n");

    // Print elements of stack1
    while (top1 != NULL) {
        printf("%d\n", top1->data);
        top1 = top1->next;
    }

    // Print elements of stack2 in reverse order
    struct node* temp = top2;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    int f = 0, a;
    char ch = 'y';
    q->stack1 = NULL;
    q->stack2 = NULL;
    while (ch == 'y' || ch == 'Y') {
        printf("Enter your choice:\n1. Add to queue\n2. Remove from queue\n3. Display\n4. Exit\n");
        scanf("%d", &f);
        switch (f) {
            case 1:
                printf("Enter the element to be added to the queue: ");
                scanf("%d", &a);
                enqueue(q, a);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q->stack1, q->stack2);
                break;
            case 4:
                free(q); // Free dynamically allocated memory
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
