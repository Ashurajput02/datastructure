//my god
#include<stdio.h>
void pop();
int top=-1;
char stack[10];
char count[10];
int start=0;
void push(char temp)
{
    if(top>5)
{
    printf("Stack overflow\n");
    return;

}
else
    stack[++top]=temp;
}
void  pop()
{

    if(top<=-1)
    return;
    else
    {
count[start++]=stack[top--];
    }
}
int main()
{
    char arr[5]="hello";
    for(int i=0;i<5;i++)
    {
        push(arr[i]);
        
    }

for(int i=0;i<5;i++)
    {
        pop();
        
    }

 
        printf("%s",count);
    

}