#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int value = queue[front];
    front++;

    printf("Dequeued %d\n", value);

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int seek(){
    return queue[front];
}

int main() {
    // enqueue(10);
    // enqueue(20);
    // enqueue(30);

    // display();

    // dequeue();
    // dequeue();

    // display();

    // enqueue(40);
    // enqueue(50);

    // display();

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
        enqueue(jig);
        break;

        case 2:
        dequeue();
        break;

        case 3:
        display();
        break;

        case 4:
        int sim=seek();
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
