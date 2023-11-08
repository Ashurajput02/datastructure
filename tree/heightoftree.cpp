#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;

    node *right;

};

node * newnode(int data)
{
    node *temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node *  insert(node *root,int data)
{
    if(root==NULL)
    root=newnode(data);

    else if(root->data>=data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);

    return root;

}

int height(struct node*ptr)
{
    if(ptr==NULL)
    return -1;

    return max((height(ptr->left),height(ptr->right)))+1;

}
int main()
{
    node *rootptr=NULL;
    rootptr=insert(rootptr,15);
    printf("the valu4 of root ptr=%d\n",rootptr);
    rootptr=insert(rootptr,10);
    
    printf("the valu4 of root ptr=%d\n",rootptr);

    rootptr=insert(rootptr,20);
    
    printf("the valu4 of root ptr=%d\n",rootptr);
    rootptr=insert(rootptr,25);
    
    printf("the valu4 of root ptr=%d\n",rootptr);

int heighter=height(rootptr);
printf("height of the tree is=%d\n",heighter);

}