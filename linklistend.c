#include<stdio.h>
#include<stdlib.h>
void insert(int a,int p);
void printer();
struct node
{
    int data;
    struct node* link;
};
struct node * head;

int main()
{

head=NULL;//suggests the list is empty so far
printf("Enter data to be added\n");
int n;
int p;
scanf("%d",&n);
    printf("enter the position where to be added\n");
    scanf("%d",&p);
    insert(n,p);//to insert the node at the required position
    printer();//to display list on screen
return 0;
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