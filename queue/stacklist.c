#include<stdio.h>
#include<stdlib.h>
int main(){
 push(1);
 push(2);
 push(3);
 push(4);
 display();
 pop();
 push(7);
 display();
}

struct node {
    int data;
    struct node *link;

};
struct node *head;
 void push(int x){
 struct node * temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->link=NULL;

if(isempty()){
    head=temp;

}
else if (isfull()){
    printf("stackoverflow\n");
    return ;
}
else
{
    temp->link=head;
    head=temp;
}
 }
void pop(){
    if(isempty()){
        printf("nothing to pop out\n");
        return ;

    }

    else{
        struct node *temp2=head;

        head=head->link;
        free(temp2);
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->link;
    } 
}

int isempty(){
    if(head==NULL)
    return 1;
    else
    return 0;

}

int isfull(){

    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    if(temp1==NULL)
    return 1;
    else
    return 0;
}