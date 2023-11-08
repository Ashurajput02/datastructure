#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* push(struct node* s, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;

    if (isempty(s)) {
        s = temp;
    } else if (isfull(s)) {
        printf("Stack overflow\n");
        return s;
    } else {
        temp->link = s;
        s = temp;
    }

    return s;
}

int pop(struct node** s) {
    if (isempty(*s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        struct node* temp = *s;
        int k = temp->data;
        *s = (*s)->link;
        free(temp);
        return k;
    }
}

void display(struct node* s) {
    struct node* temp = s;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int isempty(struct node* s) {
    if (s == NULL)
        return 1;
    else
        return 0;
}

int isfull(struct node* s) {
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    if (temp1 == NULL)
        return 1;
    else
        return 0;
}

struct node* s1 = NULL;
struct node* s2 = NULL;

void enque(int x) {
    s1 = push(s1, x);
}

void dequeue() {
    if (isempty(s1) && isempty(s2)) {
        printf("Queue is empty\n");
        return;
    }

    if (isempty(s2)) {
        while (!isempty(s1)) {
            int k = pop(&s1);
            s2 = push(s2, k);
        }
    }

    pop(&s2);

    if (isempty(s1)) {
        while (!isempty(s2)) {
            int k = pop(&s2);
            s1 = push(s1, k);
        }
    }
}

int main() {
    enque(1);
    enque(2);
    enque(3);
    enque(4);

    display(s1);

    dequeue();
    display(s1);

    enque(7);
    display(s1);

    return 0;
}
