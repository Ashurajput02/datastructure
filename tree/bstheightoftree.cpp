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

int heightleft(struct node*ptr)
{ int n=0;
    if(ptr==NULL)
    return n;
    else if(ptr!=NULL)
    {
        n++;
        int k=heightleft(ptr->left);
    }

}

int heightright(struct node*ptr)
{ int m=0;
    if(ptr==NULL)
    return m;
    else if(ptr!=NULL)
    {
        m++;
        int k=heightright(ptr->right);
    }

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
int right=heightright(rootptr);

int left=heightleft(rootptr);
if(right>=left)
printf("height of the tree is=%d\n",right);
else
printf("height of the tree is=%d\n",left);

}