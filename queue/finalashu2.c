#include<stdio.h>
#include<stdlib.h>
int main(){
    enque(1);
    enque(2);
    enque(3);
    enque(2);
    enque(5);
    display();
    duplicate();

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

void duplicate(){
    for(int i=front;i<=rear;i++){
        for(int j=i+1;j<=rear;j++){
            if(arr[i]==arr[j])
            printf("%d",arr[i]);
        break;
        }
    }
    printf("\n");
}

void highfrequency(){
    int count=0;
    
    for(int i=front;i<=rear;i++){
        int max=0;
        for(int j=i+1;j<=rear;j++){
            if(arr[i]==arr[j])
            max++;}
            if(max>=count)
            count=max;

}
printf("hihghest frequency is=");
printf("%d",(count+1));
}
