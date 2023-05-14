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


int minvalue(node *root)
{
    int minv=root->data;
    while(root->left !=NULL)
    {
        minv=root->left->data;
        root=root->left;
    }
    return minv;
}

node * deletenode(node * root,int key)
{
    if(root=NULL)
    return root;

    if(key< root->data)
    root->left=deletenode(root->left,key);

    
    else if(key> root->data)
    root->right=deletenode(root->right,key);

    else{

        if(root->right==NULL)
        return root->left;

        
        else if(root->left==NULL)
        return root->right;
 root->data=minvalue(root->right);
 
 root->right=deletenode(root->right,root->data);
    }
    return root;
}

void inorder(node * root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}
  int main()
  {
    node *rootptr=NULL;
     rootptr=insert(rootptr,30);
     rootptr=insert(rootptr,28);
     rootptr=insert(rootptr,40); 
     rootptr=insert(rootptr,20);
     rootptr=insert(rootptr,25);
     rootptr=insert(rootptr,10);
     rootptr=insert(rootptr,5);
     rootptr=insert(rootptr,22); 
     rootptr=insert(rootptr,27);

deletenode(rootptr,20);
    inorder(rootptr);
    
  }