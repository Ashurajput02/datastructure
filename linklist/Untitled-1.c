#include<stdio.h>
#include<stdlib.h>
void reverse();
void print();
void insert(int k);
struct node
{
    int data;
    struct node*link;
};
struct node *head=NULL;
int main()
{
    printf("enter number of elements to be present in the list\n");
    int n;
    scanf("%d",&n);
    int x;
    printf("enter the numbers\n");
    for(int i=0;i<n;i++)
    scanf("%d",&x);
    insert(x);

printf("the list is:\n");
print();
//printf("the list in reverse order is:\n");
//reverse();
//print();
return 0;
}
 void insert(int k)
{
    struct node *temp=(struct node *)malloc(sizeof( struct node));
  temp->data=k;
  temp->link=head;
  head=temp;
}

void print()
{ struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",(temp->data));
        temp=temp->link;
    }
    printf("\n");

}


void reverse()
{
    struct node *current,*prev,*next;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
}