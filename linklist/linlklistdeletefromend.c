#include<stdio.h>
#include<stdlib.h>
void insert(int a,int b);
void printer();
void delete(int n);

struct node
{
    int data;
    struct node* link;
};
struct node * head;

int main()
{

head=NULL;//suggests the list is empty so far
 insert(1,1);
    insert(2,2);
    insert(3,3);
    insert(4,4);
    printf("before deleting end node\n");
    printer();
    printf("enter deleting end node\n");
    
delete(4);
printer();
}



void insert(int a,int p)
{

    struct node *temp1=(struct node *)malloc(sizeof( struct node));//most imp
    temp1->data=a;//the value at the address stored in temp uspe data
    temp1->link=NULL;
    if(p==1)
    {
        temp1->link=head;
        head=temp1;
        return;

    }
     struct node *temp2=head;
    for(int i=0;i<p-2;i++)//to attain the address of n-1 node
    {
        temp2=temp2->link;
    }


        temp1->link=temp2->link;
        temp2->link=temp1;

    }


void delete(int n)
{

struct node*temp=head;
for(int i=0;i<n-2;i++)
temp=temp->link;

struct node *temp2=temp->link;
temp->link=temp2->link;
free(temp2);
}

 void printer()
{
    struct node * temp=head;
    printf("list is:\n");
 while(temp!=NULL)
 {
    printf("%d",temp->data);
    temp=temp->link;
 }
 printf("\n");
}