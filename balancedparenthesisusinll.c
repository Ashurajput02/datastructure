#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node *link;
};
//struct node *head=NULL;
struct node* push(struct node *head ,int x){
    int k=isfull(head);
    if(k==1)
    {
        struct node *temp=(struct node* )malloc(sizeof(struct node));
        temp->data=x;
        temp->link=head;
        head=temp;
        return head;
    }
    else{
        printf("Stack Overflow\n");
        return head;}

    }

    int pop(struct node** head){
        int k=(*head)->data;
        *head=(*head)->link;
        return k;

    }

    int top(struct node*head)
    {
        int k=(head)->data;
        return k;
    }

    int isempty(struct node*head){
        if (head==NULL)
        return 1;
        else
        return 0;

    }

    int isfull(struct node*head){
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
// head=push(head ,5);
// head=push(head,6);
// printf("the elements in the stack are:\n");
// printer(head);
// head=push(head,7);
// head=push(head,8);
// int k=pop(&head);

// printf("popped element is :%d\n",k);
// printer(head);
// printf("%d",isempty(head));
int n;
printf("enter size\n");
scanf("%d",&n);
printf("enter the expression\n");
char arr[n];
scanf("%d",arr);
for(int i=0;i<n;i++)
{
    if(arr[i]=='('||arr[i]=='['||arr[i]=='{')
    push(head,arr[i]);

    else if(arr[i]==')'||arr[i]==']'||arr[i]=='}'){
    
    char k=pop(&head);
    if(k=='('&& arr[i]==')')
    continue;
    else if(k=='{'&& arr[i]=='}')
        continue;
else if(k=='['&& arr[i]==']')
continue;
else
{
    printf("not balanced\n");
    break;

}
    }
}
if(head==NULL)
printf("balanced\n");
}












   