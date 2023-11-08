#include<stdio.h>
#include<stdlib.h>
int main(){
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

#define n 10
int arr[n];
int front=-1;
int rear=-1;

void enque(int x){
    if(isempty()){
        front=(front+1)%n;
        rear=(rear+1)%n;

    }

    if(isfull()){
    printf("queue overflow\n");
    return ;
    }


    else
    rear=(rear+1)%n;
}

void dequeue(){

    if(isempty())
    {
        printf("nothing to dequeue\n");
        return ;

    }

    else if(front == rear){
    front=-1;
    rear=-1;}

    else
    front=(front+1)%n;
}

void display(){

    if(isempty()){
        printf("no element in the list");
        return ;}
        else{

            if(front<rear){

                for(int i=front ;i<=rear;i++)
                printf("%d",arr[i]);

            }

            else{

                for (int j=front;j<=n-1;j++)
                printf("%d",arr[j]);

                for(int p=0;p<=rear;p++)
                printf("%d",arr[p]);


            }

        }
        printf("\n");
}

int isempty(){

    if(front==-1)
    return 1;
    else
    return 0;
}

int isfull(){

    if(rear==n-1||rear==front-1)
    return 1;
    else return 0;

}