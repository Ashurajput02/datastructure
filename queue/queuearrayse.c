#include<stdio.h>
#include<stdlib.h>
int main(){

    enque(1);
    
    enque(7);
    enque(6);
    enque(5);
    enque(4);

    display();
    dequeue();
    display();
    enque(9);
    enque(2);
    display();
    dequeue();
    display();
    int ashu=peek();
    printf("%d",ashu);

}

#define n 1000
int arr[n];
int front=-1;
int rear=-1;
void enque(int x){
    if(isempty()){
        front++;
        rear++;
        arr[rear]=x;
    }

    else if(isfull()){
        printf("queue overflow\n");
        return;

    }

    else{
        arr[++rear]=x;
    }
}

void dequeue(){
    if(isempty()){
        printf("nothing to dequeue\n");
        return ;
}

else if(front==rear){
    front=-1;
    rear=-1;
}

else 
front++;
}
void display(){

    if(front==-1)
    printf("list is empty\n");
    else{
        for(int i=front;i<=rear;i++)
        printf("%d",arr[i]);

        printf("\n");
    }
}

int isempty(){
    if(front==-1)
    return 1;
    else 
    return 0;

}

int isfull(){
    if(rear==n-1)
    return 1;
    else return 0;

}

int peek(){
    return arr[front];
}