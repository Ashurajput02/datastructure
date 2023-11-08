#include<stdio.h>
#include<stdlib.h>
#define n 100
int arr[n];
int top=-1;

int main(){

    push(5);
    push(6);
    push(7);
    push(8);
    display();
    pop();
    display();
    push(4);
    display();
}

void push(int x){
    if(isempty()){
    top++;
    arr[top]=x;
    }
    else if(isfull())
    {
        printf("Stack Overflow\n");
        return ;
    }
    else
    arr[++top]=x;

}

void pop(){
    if(isempty()){
        printf("nothing to pop\n");
    }
    else
        top--;

}

void display(){
    
    for(int i=0;i<=top;i++)
    printf("%d",arr[i]);

    printf("\n");
}

int isempty(){
    if(top==-1)
    return 1;
    else return 0;
}

int isfull(){
    if(top==n-1)
    return 1;
    else
    return 0;

}