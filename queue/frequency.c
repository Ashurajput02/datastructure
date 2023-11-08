
int countFrequency() {
    int count = 0;
struct node *temp=front;
    if (isEmpty()) {
        return count;
    }

    for (int i = temp; i <=rear; i++) {
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


#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *front=NULL;
struct node *rear=NULL;
int main(){
    enque(5);
    enque(6);
    enque(7);
    enque(8);
    enque(2);
    enque(1);
enque(77);
}



void enque(int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(isempty()){
front=temp;
rear=temp;
    }
    else if(isfull()){
        printf("queue overflow\n");
        return ;
    }

else{
    rear->next=temp;
    rear=temp;
}
}

void dequeue(){
    if(isempty()){
        printf("nothing to dequeue\n");
        return ;
    }

        else{
            struct node *temp2=front;
            front=front->next;
            free(temp2);
        } 
}

int isempty(){

    if(front==NULL)
    return 1;
    else
     return 0;

}
    int isfull(){

        struct node *temp2=(struct node*)malloc(sizeof(struct node));
        if(temp2==NULL)
        return 1;
        else 
        return 0;
    }


