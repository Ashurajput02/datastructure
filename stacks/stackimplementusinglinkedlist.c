#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node *link;
};
struct node *head=NULL;
void push(int x){
    int k=isfull();
    if(k==1)
    {
        struct node *temp=(struct node* )malloc(sizeof(struct node));
        temp->data=x;
        temp->link=head;
        head=temp;
    }
    else{
        printf("Stack Overflow\n");
        return;}

    }

    int pop(){
        int k=head->data;
        head=head->link;
        return k;

    }

    int top()
    {
        int k=head->data;
        return k;
    }

    int isempty(){
        if (head==NULL)
        return 1;
        else
        return 0;

    }

    int isfull(){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        return 0;
        else
        return 1;
    }

void printer(){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
}
int main(){
push(5);
push(6);
printf("the elements in the stack are:\n");
printer();
push(7);
push(8);
int k=pop();
printf("popped element is :%d\n",k);
printf("%d",isempty());
}