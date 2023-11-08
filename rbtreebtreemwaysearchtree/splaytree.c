#include <stdio.h>
#include <stdlib.h>

typedef struct SplayNode
{
    int key;
    struct SplayNode *left;
    struct SplayNode *right;
} SplayNode;

SplayNode *createNode(int key)
{
    SplayNode *newNode = (SplayNode *)malloc(sizeof(SplayNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

SplayNode *leftRotate(SplayNode *x)
{
    SplayNode *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

SplayNode *rightRotate(SplayNode *x)
{
    SplayNode *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

SplayNode *splay(SplayNode *root, int key)
{
    if (!root || root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        if (!root->left)
        {
            return root;
        }

        if (key < root->left->key)
        {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (key > root->left->key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
            {
                root->left = leftRotate(root->left);
            }
        }

        return (root->left) ? rightRotate(root) : root;
    }
    else
    {
        if (!root->right)
        {
            return root;
        }

        if (key > root->right->key)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        else if (key < root->right->key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
            {
                root->right = rightRotate(root->right);
            }
        }

        return (root->right) ? leftRotate(root) : root;
    }
}

SplayNode *insert(SplayNode *root, int key)
{
    if (!root)
    {
        return createNode(key);
    }

    root = splay(root, key);

    if (key == root->key)
    {
        return root;
    }

    SplayNode *newNode = createNode(key);

    if (key < root->key)
    {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    }
    else
    {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}

SplayNode *delete(SplayNode *root, int key)
{
    if (!root)
    {
        return root;
    }

    root = splay(root, key);

    if (key != root->key)
    {
        return root;
    }

    SplayNode *leftSubtree = root->left;
    SplayNode *rightSubtree = root->right;
    free(root);

    if (!leftSubtree)
    {
        return rightSubtree;
    }

    leftSubtree = splay(leftSubtree, key);
    leftSubtree->right = rightSubtree;

    return leftSubtree;
}

void inOrderTraversal(SplayNode *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main()
{
    SplayNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the Splay Tree: ");
    inOrderTraversal(root);
    printf("\n");

    root = delete (root, 20);
    printf("After deleting 20: ");
    inOrderTraversal(root);
    printf("\n");

    root = delete (root, 70);
    printf("After deleting 70: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
