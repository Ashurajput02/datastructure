#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    Node* temp = queue->front;
    int value = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);

    printf("Dequeued %d\n", value);
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int seek(Queue * queue){
    return (queue->front->data);
}
int main() {
     Queue* queue = createQueue();
    int count=0;
do{
    printf("enter 1 to enqueue,2 to deque,3 to display queue and 4 to see front \n ");
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

        case 3:
        display(queue);
        break;

        case 4:
        int sim=seek(queue);
        printf("the element at the first position is:%d\n",sim);
        break;
        
        default:
        printf("wrong choice\n");
    }


printf("enter 1 to exit \n");
scanf("%d",&count);
}while(count!=1);

    return 0;
}
