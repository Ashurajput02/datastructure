#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
void insert(int k);
void print();

struct node *head=NULL;

int main()
{
int n;
printf("enter number of nodes needed\n");
scanf("%d",&n);int x;
for(int i=1;i<=n;i++)
{
    print("enter\n");
    scanf("%d",&x);
    insert(x);
}
print();
return 0;
}


void insert(int k)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=k;
    temp->link=head;
    head=temp;
}

void print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}