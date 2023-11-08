#include<stdio.h>
#include<stdlib.h>
int main(){
printf("enter length of string\n");
int tashu;
scanf("%d",&tashu);
    printf("enter the string\n");
    char str[tashu];
    scanf("%s", str);
for(int jiggi=0;jiggi<tashu;jiggi++){
    push(str[jiggi]);
}
   for(int sim=0;sim<tashu;sim++){
    char kenya=front();
    if(str[sim]==kenya)
    pop();
   }
   if(isempty(head))
   printf("yes its palindrome\n");
   else
   printf("no its not a palindrome\n");
}

struct node {
    char data;
    struct node *link;

};
struct node *head;

 void push(char x){
 struct node * temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->link=NULL;

if(isempty()){
    head=temp;

}
else if (isfull()){
    printf("stackoverflow\n");
    return ;
}
else
{
    temp->link=head;
    head=temp;
}
 }
void pop(){
    if(isempty()){
        printf("nothing to pop out\n");
        return ;

    }

    else{
        struct node *temp2=head;

        head=head->link;
        free(temp2);
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->link;
    } 
}

int isempty(){
    if(head==NULL)
    return 1;
    else
    return 0;

}

int isfull(){

    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    if(temp1==NULL)
    return 1;
    else
    return 0;
}

char front(){
    return(head->data);
}