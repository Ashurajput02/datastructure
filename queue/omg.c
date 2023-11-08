#include <stdio.h>
#include <stdlib.h>

#define n 1000

int arr[n];
int front = -1;
int rear = -1;

void enque(int x);
void dequeue();
void display();
int isempty();
int isfull();
int peek();
void duplicate();
void highfrequency();

int main() {
    // enque(1);
    // enque(2);
    // enque(3);
    // enque(2);
    // enque(5);

    printf("enter the total number of numbers\n");
    int jiggi;
    scanf("%d",&jiggi);

    for(int sim=0;sim<jiggi;sim++)
    {
        int ashu ;
        scanf("%d",&ashu);
        enque(ashu);
    }

    duplicate();
    highfrequency();

    return 0;
}

void enque(int x) {
    if (isempty()) {
        front++;
        rear++;
        arr[rear] = x;
    } else if (isfull()) {
        printf("queue overflow\n");
        return;
    } else {
        arr[++rear] = x;
    }
}

void dequeue() {
    if (isempty()) {
        printf("nothing to dequeue\n");
        return;
    } else if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("list is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int isempty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if (rear == n - 1)
        return 1;
    else
        return 0;
}

int peek() {
    return arr[front];
}

void duplicate() {
    int meta=0;
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                meta++;
                break;
            }
        }
    }
    printf("\n");
    printf(" numbers being repeated %d",meta);
    printf("\n");
}

void highfrequency() {
    int count = 0;
    int max = 0;

    for (int i = front; i <= rear; i++) {
        max = 0;
        for (int j = i + 1; j <= rear; j++) {
            if (arr[i] == arr[j]) {
                max++;
            }
        }
        if (max > count) {
            count = max;
        }
    }

    printf("highest frequency is: %d\n", count + 1);
}
