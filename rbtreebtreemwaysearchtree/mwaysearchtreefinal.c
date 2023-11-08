#include <stdio.h>
#include <stdlib.h>

#define M 4

typedef struct MWayTreeNode {
    int keys[M - 1];
    struct MWayTreeNode *children[M];
    int num_keys;
} MWayTreeNode;

MWayTreeNode *createNode() {
    MWayTreeNode *newNode = (MWayTreeNode *)malloc(sizeof(MWayTreeNode));
    newNode->num_keys = 0;
    for (int i = 0; i < M; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

MWayTreeNode *search(MWayTreeNode *node, int key) {
    int i = 0;
    while (i < node->num_keys && key > node->keys[i]) {
        i++;
    }
    if (i < node->num_keys && key == node->keys[i]) {
        return node;
    }
    if (node->children[i] != NULL) {
        return search(node->children[i], key);
    } else {
        return NULL;
    }
}

MWayTreeNode *insert(MWayTreeNode *node, int key) {
    int i = node->num_keys - 1;

    if (node->num_keys == M - 1) {
        int keyToPromote = node->keys[M / 2];
        MWayTreeNode *newNode = createNode();

        for (int j = M / 2 + 1; j < M - 1; j++) {
            newNode->keys[j - M / 2 - 1] = node->keys[j];
            node->keys[j] = 0;
            newNode->children[j - M / 2 - 1] = node->children[j];
            node->children[j] = NULL;
        }
        newNode->children[M / 2 - 1] = node->children[M - 1];
        node->num_keys = M / 2;

        if (key < keyToPromote) {
            node = insert(node, key);
        } else {
            newNode = insert(newNode, key);
        }

        MWayTreeNode *newParent = createNode();
        newParent->keys[0] = keyToPromote;
        newParent->children[0] = node;
        newParent->children[1] = newNode;
        newParent->num_keys = 1;

        return newParent;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;

        return node;
    }
}

void printInOrder(MWayTreeNode *node) {
    if (node) {
        for (int i = 0; i < node->num_keys; i++) {
            printInOrder(node->children[i]);
            printf("%d ", node->keys[i]);
        }
        printInOrder(node->children[node->num_keys]);
    }
}

void traverseInOrder(MWayTreeNode *node) {
    if (node) {
        for (int i = 0; i < node->num_keys; i++) {
            traverseInOrder(node->children[i]);
            printf("%d ", node->keys[i]);
        }
        traverseInOrder(node->children[node->num_keys]);
    }
}

int main() {
    MWayTreeNode *root = createNode();

    int choice = 0;
    while (1) {
        printf("Enter:\n 1. Insert\n2. Search\n 3.Traverse\n-1. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int key;
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
        } else if (choice == 2) {
            int keyToSearch;
            printf("Enter key to search: ");
            scanf("%d", &keyToSearch);

            MWayTreeNode *searchResult = search(root, keyToSearch);
            if (searchResult != NULL) {
                printf("Key %d found in the m-way search tree!\n", keyToSearch);
            } else {
                printf("Key %d not found in the m-way search tree.\n", keyToSearch);
            }
        }
        else if (choice == 3) {
            traverseInOrder(root);
        }

        else if (choice == -1) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    printf("In-order traversal of the m-way search tree: ");
    printInOrder(root);
    printf("\n");

    return 0;
}


/*
MWayTreeNode *delete(MWayTreeNode *node, int key) {
    if (node == NULL) {
        // Key not found, nothing to delete
        return node;
    }

    int i = 0;
    while (i < node->num_keys && key > node->keys[i]) {
        i++;
    }

    if (i < node->num_keys && key == node->keys[i]) {
        // Key found in the current node
        // Shift keys to the left to remove the key
        for (int j = i; j < node->num_keys - 1; j++) {
            node->keys[j] = node->keys[j + 1];
        }
        node->keys[node->num_keys - 1] = 0;
        node->num_keys--;

        // If the node becomes empty, update the parent
        if (node->num_keys == 0) {
            free(node);
            return NULL;
        }

        return node;
    } else {
        // Key not found in the current node, search in child nodes
        node->children[i] = delete(node->children[i], key);
        return node;
    }
}
yeh leaf node kje deletion ka simple code h bro isse jyada chedh mat lena

*/
