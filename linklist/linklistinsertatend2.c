#include<stdio.h>
#include<stdlib.h>
void insert(int a);
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
printf("how many numbers\n");
int n;
int x;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
    printf("enter the number\n");
    scanf("%d",&x);
    insert(x);
   
}  
 printer();  
return 0;
}

void insert(int a)
{

    struct node *temp=(struct node *)malloc(sizeof( struct node));//most imp
   temp->data=a;
   temp->link=NULL;
   struct node*temp2=head;
   if(head==NULL){
   head=temp;
   return;}

   else{
    while(temp2->link!=NULL)
    temp2=temp2->link;

    temp2->link=temp;


   }
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