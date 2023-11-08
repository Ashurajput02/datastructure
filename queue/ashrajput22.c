#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

struct Queue createQueue() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

void enqueue(struct Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear++;
    q->data[q->rear] = element;
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

int countFrequency(struct Queue* q, int num) {
    int count = 0;

    if (isEmpty(q)) {
        return count;
    }

    for (int i = q->front; i <= q->rear; i++) {
        if (q->data[i] == num) {
            count++;
        }
    }

    return count;
}

void printDuplicateElements(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No duplicate elements.\n");
        return;
    }

    printf("Duplicate elements in the queue: ");

    for (int i = q->front; i <= q->rear; i++) {
        for (int j = i + 1; j <= q->rear; j++) {
            if (q->data[i] == q->data[j]) {
                printf("%d ", q->data[i]);
                break;
            }
        }
    }

    printf("\n");
}

void printHighestFrequency(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to calculate frequency.\n");
        return;
    }

    int highestFrequency = 0;
    int mostFrequentNum;

    for (int i = q->front; i <= q->rear; i++) {
        int frequency = countFrequency(q, q->data[i]);

        if (frequency > highestFrequency) {
            highestFrequency = frequency;
            mostFrequentNum = q->data[i];
        }
    }

    printf("The number with the highest frequency: %d\n", mostFrequentNum);
    printf("Frequency: %d\n", highestFrequency);
}

int main() {
    struct Queue queue = createQueue();

       int count=0;
do{
    printf("enter 1 to enqueue,2 to deque\n ");
    int tashu;
    scanf("%d",&tashu);
    switch (tashu){

        case 1:
        printf("enter the data to enque\n");
        int jig;
        scanf("%d",&jig);
        enqueue(queue,jig);
        break;

        case 2:
        dequeue(queue);
        break;

        default:
        printf("wrong choice\n");
    }
printf("enter 1 to exit \n");
scanf("%d",&count);
}while(count!=1);
    printDuplicateElements(&queue);
    printHighestFrequency(&queue);
    return 0;
}
