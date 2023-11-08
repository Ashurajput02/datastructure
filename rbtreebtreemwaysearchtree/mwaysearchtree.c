#include <stdio.h>
#include <stdlib.h>

#define M 4 // Specify the order of the m-way search tree (e.g., 4-way tree)

// Structure to represent a node in the m-way search tree
typedef struct MWayTreeNode
{
    int keys[M - 1];                  // Array of keys
    struct MWayTreeNode *children[M]; // Array of child pointers
    int num_keys;                     // Number of keys in the node
} MWayTreeNode;

// Create a new node for the m-way tree
MWayTreeNode *createNode()
{
    MWayTreeNode *newNode = (MWayTreeNode *)malloc(sizeof(MWayTreeNode));
    newNode->num_keys = 0;
    for (int i = 0; i < M; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Search for a key in the m-way search tree
MWayTreeNode *search(MWayTreeNode *node, int key)
{
    int i = 0;
    while (i < node->num_keys && key > node->keys[i])
    {
        i++;
    }
    if (i < node->num_keys && key == node->keys[i])
    {
        return node;
    }
    if (node->children[i] != NULL)
    {
        return search(node->children[i], key);
    }
    else
    {
        return NULL;
    }
}

// Insert a key into the m-way search tree
MWayTreeNode *insert(MWayTreeNode *node, int key)
{
    int i = node->num_keys - 1;

    if (node->num_keys == M - 1)
    {
        // Node is full, we need to split it.
        int keyToPromote = node->keys[M / 2];
        MWayTreeNode *newNode = createNode();

        // Move keys and children to the new node
        for (int j = M / 2 + 1; j < M - 1; j++)
        {
            newNode->keys[j - M / 2 - 1] = node->keys[j];
            node->keys[j] = 0; // Clear the original node's keys
            newNode->children[j - M / 2 - 1] = node->children[j];
            node->children[j] = NULL; // Clear the original node's child pointers
        }
        newNode->children[M / 2 - 1] = node->children[M - 1];
        node->num_keys = M / 2;

        if (key < keyToPromote)
        {
            node = insert(node, key);
        }
        else
        {
            newNode = insert(newNode, key);
        }

        // Promote the key to the parent
        MWayTreeNode *newParent = createNode();
        newParent->keys[0] = keyToPromote;
        newParent->children[0] = node;
        newParent->children[1] = newNode;
        newParent->num_keys = 1;

        return newParent;
    }
    else
    {
        // Node is not full, insert key into the node
        while (i >= 0 && key < node->keys[i])
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;

        return node;
    }
}

int main()
{
    MWayTreeNode *root = createNode(); // Create the root node for the m-way search tree

    int choice = 0;
    while (1)
    {
    printf("Enter:\n
    1.Insert \n
    2.Deletion \n
    3.Search\n
    -1.Exit\n");

    scanf("%d",&choice);
    if(choice==1){
            int key;
            scanf("%d", &key);
            root = insert(root, key);
    }

    else if(choice==2)
    {

    }

    else if(choice==3)
    {
            int keyToSearch;
            printf("enter key to be searched:");
            scanf("%d", &keyToSearch);

            MWayTreeNode *searchResult = search(root, keyToSearch);
            if (searchResult != NULL)
            {
                printf("Key %d found in the m-way search tree!\n", keyToSearch);
            }
            else
            {
                printf("Key %d not found in the m-way search tree.\n", keyToSearch);
            }

    }
    else if (choice ==-1)
    break;
    else
    printf("wrong choice\n");
    }
    return 0;
}
