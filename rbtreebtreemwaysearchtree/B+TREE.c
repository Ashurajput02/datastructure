#include <stdio.h>
#include <stdlib.h>

#define M 3 // Order of B+ tree

typedef struct Node
{
    int keys[M - 1];
    struct Node *child[M];
    struct Node *next;
    int isLeaf;
    int n;
} Node;

Node *root = NULL;

Node *createNode(int isLeaf)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->isLeaf = isLeaf;
    newNode->n = 0;
    newNode->next = NULL;
    return newNode;
}

void insert(int key)
{
    if (root == NULL)
    {
        root = createNode(1);
        root->keys[0] = key;
        root->n = 1;
        return;
    }
    Node *currentNode = root;
    Node *parent = NULL;

    while (!currentNode->isLeaf)
    {
        int i = 0;
        while (i < currentNode->n && key > currentNode->keys[i])
            i++;
        parent = currentNode;
        currentNode = currentNode->child[i];
    }

    int i = 0;
    while (i < currentNode->n && key > currentNode->keys[i])
        i++;

    // Shift keys and children to make room for the new key
    for (int j = currentNode->n; j > i; j--)
    {
        currentNode->keys[j] = currentNode->keys[j - 1];
        currentNode->child[j] = currentNode->child[j - 1];
    }

    // Insert the key
    currentNode->keys[i] = key;
    currentNode->n++;

    // Split if the node is full
    if (currentNode->n == M - 1)
    {
        // Create a new node for splitting
        Node *newNode = createNode(1);

        // Move the right half of keys and children to the new node
        int mid = currentNode->n / 2;
        for (int j = mid; j < M - 1; j++)
        {
            newNode->keys[j - mid] = currentNode->keys[j];
            newNode->child[j - mid] = currentNode->child[j];
            newNode->n++;
            currentNode->n--;
        }

        // Update parent and link new node
        newNode->next = currentNode->next;
        currentNode->next = newNode;

        // Handle root split
        if (currentNode == root)
        {
            Node *newRoot = createNode(0);
            newRoot->keys[0] = newNode->keys[0];
            newRoot->child[0] = currentNode;
            newRoot->child[1] = newNode;
            newRoot->n = 1;
            root = newRoot;
        }
        else
        {
            // Insert the middle key into the parent
            insert(newNode->keys[0]);
            newNode->keys[0] = 0;
            newNode->n--;
        }
    }
}
void traverse(Node *currentNode)
{
    if (currentNode != NULL)
    {
        int i;
        for (i = 0; i < currentNode->n; i++)
        {
            traverse(currentNode->child[i]);
            printf("%d ", currentNode->keys[i]);
        }
        traverse(currentNode->child[i]); // Traverse the rightmost child
    }
}

int main()
{
    // int keys[] = {5, 9, 3, 7, 2, 8, 4, 1, 6};

    // for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
    // {
    //     insert(keys[i]);
    // }
    int choice = 0;
    while (1)
    {
        printf("Enter:\n 1. Insert\n2. Search\n 3.Traverse\n-1. Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int key;
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
        }
        else if (choice == 2)
        {
        }
        else if (choice == 3)
        {
            printf("B+ tree traversal: ");
            traverse(root);
        }

        else if (choice == -1)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
