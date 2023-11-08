#include<stdio.h>
#include<stdlib.h>
struct node * insert(struct node *head,int a);
void printer();
struct node
{
    int data;
    struct node* link;
};


int main()
{

 struct node *head=NULL;//suggests the list is empty so far
printf("how many numbers\n");
int n;
int x;
scanf("%d",&n);
int arr[3]={1,2,3};
for(int i=0;i<3;i++){
head=insert(head ,arr[i]);
}
 printer(head);  
return 0;
}

struct node * insert( struct node * head,int a)
{

    struct node *temp=(struct node *)malloc(sizeof( struct node));//most imp
    temp->data=a;//the value at the address stored in temp uspe data 
    temp->link=NULL;//derefrencing pointer variable to store value
    if(head!=NULL)
    temp->link=head;/*isse kya hoga yadi a nonempty hoga toh a ka address will be stored in new node and iss new node ka address will be stored in head vioa next line*/
    head=temp;
    
}

 void printer(struct node * head)
{
    struct node * temp=head;
    int k=0;
 while(temp!=NULL)
 {
   printf("%d",temp->data);
   temp=temp->link;
   k++;
 }
 printf("number of nodes added=%d\n",k);
}