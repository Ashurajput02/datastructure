#include<stdio.h>
#include<stdlib.h>
void insertathead1(int x);
void insertathead2(int x);
struct node1{//for singly linked list
    int data;
    struct node *link;
};
struct node1 * head1; 
struct node2{//for doubly linked list
    int data;
    struct node *prev;
    struct node *next;
};
struct node2 *head2;

struct node1  * newnode1(int x)
{
    struct node1 *temp=(struct node1 *)malloc(sizeof( struct node1));
    temp->data=x;
    temp->link=NULL;
    return temp;
}//to create a new singly linked node


struct node2 *newnode2(int x)
{//to create a doubly linked node
    struct node2 *temp=(struct node2 *)malloc(sizeof( struct node2));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

void insertathead1(int x)
{
struct node1 *temp=newnode1(x);
if(head1==NULL)
{
    head1=temp;
    return;
}
temp->link=head1;
head1=temp;


}



void insertathead2(int x)
{
struct node2 *temp=newnode2(x);
if(head2==NULL)
{
    head2=temp;
    return;
}
head2->prev=temp;
temp->next=head2;
head2=temp;
}

void print1()
{
        struct node *temp=head1;
        
}


int main()
{
    printf("enter 1 for SINGLY LINKED LIST\n");
    
    printf("enter 2 for DOUBLY LINKED LIST\n");
    int choice;
    scanf("%d",&choice);

    if(choice==1){
    printf("1.Enter a node at the head\n");
    
    printf("2.Enter a node at the tail\n");
    
    printf("3.Insert a node at a particular position\n");
    
    printf("4.Delete a node at a particular position\n");

    int n;
    int x;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        printf("enter data to be entered\n");
        scanf("%d",&x);
        //newnode1(x);
        insertathead1(x);
          break;
        case 2:
        printf("enter data to be entered\n");
        scanf("%d",&x);
        insertathead1(x);
        break;
    
    }
}
else if(choice==2)
{
    printf("1.Enter a node at the head\n");
    
    printf("2.Enter a node at the tail\n");
    
    printf("3.Insert a node at a particular position\n");
    
    printf("4.Delete a node at a particular position\n");

    int n;
    int x;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        printf("enter data to be entered\n");
        scanf("%d",&x);
        //newnode1(x);
        insertathead2(x);
          break;
        case 2:
        printf("enter data to be entered\n");
        scanf("%d",&x);
        insertathead2(x);
        break;
    
    }
}
return 0;
}
