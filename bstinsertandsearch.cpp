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
bool search(node * temp2,int x)
{
if(temp2==NULL) 
return false;
else if(x==temp2->data)
return true;

else if(x<=temp2->data)
return search(temp2->left,x);
else if(x>=temp2->data)
return search(temp2->right,x);
}

int maxima(node *root)
{
    static int max=0;
    if(max<=root->data)
    {
        max=root->data;
        maxima(root->right);

    }

    return max;

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
    /*
    printf("enter number to be searched:\n");
   int x;
    scanf("%d",&x);
    int result=search(rootptr,x);
 
printf("%d\n",result);*/
int max=maxima(rootptr);
printf("the maximum element is=%d\n",max);
}


