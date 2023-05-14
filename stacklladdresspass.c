#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node *link;
};
//struct node *head=NULL;
void push(struct node **head ,int x){
    int k=isfull(*head);
    if(k==1)
    {
        struct node *temp=(struct node* )malloc(sizeof(struct node));
        temp->data=x;
        temp->link=*head;
        *head=temp;
        
    }
    else{
        printf("Stack Overflow\n");
        }

    }

    int pop(struct node** head){
        int k=(*head)->data;
        *head=(*head)->link;
        return k;

    }

    int top(struct node*head)
    {
        int k=head->data;
        return k;
    }

    int isempty(struct node**head){
        if (*head==NULL)
        return 1;
        else
        return 0;

    }

    int isfull(struct node**head){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        return 0;
        else
        return 1;
    }

void printer(struct node*head){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main(){
struct node *head=NULL;
push(&head ,5);
push(&head,6);
printf("the elements in the stack are:\n");
printer(head);
push(&head,7);
push(&head,8);
int k=pop(&head);
printf("popped element is :%d\n",k);
printf("%d",isempty(&head));
}