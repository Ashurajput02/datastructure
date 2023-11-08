
#include <stdio.h>
int arr[10];
int front=-1;
int rear=-1;
void en(int x)
{
    
    if(front==-1 &&rear==-1){
    front++;
    rear++;
    arr[front]=x;}
    
    else if(rear==10-1){
    printf("Queue overflow\n");
    return;}
    else
    arr[++rear]=x;
}


void deq()
{
    if(front==-1)
    printf("nothing to delete\n");
    else
    front++;
    
}

void frontend()
{
    printf("%d\n",arr[front]);
}

void isempty()
{
    if(front==-1 && rear==-1)
    printf("yes its empty\n");
    else
    printf("not empty\n");
}
int main()
{
    printf("how many numbers\n");
    int n;
    scanf("%d",&n);
    int x;

    for(int i=0;i<n;i++)
    {
       printf("Enter the number\n");
    
        scanf("%d",&x);
         en(x);
    }
    int exit=1;
    while(exit!=0)
{

    printf("enter 1 to de-enque and 2 to print front element and 3 to check if queue is empty or not and 4 to add a new element \n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    deq();
    else if (choice==2)
    frontend();
    
    else if(choice==3)
    isempty();


    else if(choice==4)
    {
printf("enter number to be added\n");
int k;
scanf("%d",&k);
    en(k);}

    else
    printf("wrong input\n");

printf("enter 0 to exit\n");
scanf("%d",&exit);
}
    
    return 0;
}
