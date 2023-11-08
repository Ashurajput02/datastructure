#include<iostream>
using namespace std;
struct node {
    int value;
    struct node *next;
    struct node *child;
};
struct node *head=NULL;

struct node *create(int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->value=x;
    temp->next=NULL;
    temp->child=NULL;
    return (temp);
}

void createNode(int u,int v,int type){
    struct node *temp=head;
    struct node *ptr1=NULL;
    struct node *ptr2=NULL;
    while(temp!=NULL){
        if(temp->value==u)
        ptr1=temp;

        if(temp->value==v)
        ptr2=temp;

        temp=temp->next;

    }
    if(ptr1!=NULL && ptr2==NULL)
ptr2=create(v);

else if(ptr1==NULL && ptr2!=NULL)
ptr1=create(u);

else if(ptr1==NULL && ptr2==NULL && head!=NULL){
    ptr1=create(u);
    ptr2=create(v);
    
}
else{
    ptr1=create(u);
    ptr2=create(v);
 head=ptr1;   
}
}



int main(){

createNode(4,7,1);
createNode(1,2,0);
cout<<head->value<<endl;
cout<<(head->next->value)<<endl;
return 0;
}
