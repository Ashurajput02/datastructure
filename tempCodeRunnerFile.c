#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>

#define bucketSize 3

// Create 2 structures, one for node and one for tree;

typedef struct Node {
    bool isLeaf;
    struct Node* ptr[bucketSize + 1];
    int key[bucketSize - 1];
    int size;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isLeaf = false;
    newNode->size = 0;
    for (int i = 0; i < bucketSize + 1; i++) {
        newNode->ptr[i] = NULL;
    }
    return newNode;
}

typedef struct BPlusTree {
    Node* root;
} BPlusTree;

BPlusTree* createBPlusTree() {
    BPlusTree* tree = (BPlusTree*)malloc(sizeof(BPlusTree));
    tree->root = NULL;
    return tree;
}

void deleteNode(BPlusTree* tree, int x) {
    // Your deletion logic here
    // You can implement deletion similar to insertion
}

int search(BPlusTree* tree, int x) {
    Node* current = tree->root;
    if (current == NULL) {
        return -1;
    }

    while (!current->isLeaf) {
        for (int i = 0; i < current->size; i++) {
            if (x < current->key[i]) {
                current = current->ptr[i];
                break;
            }

            if (i == current->size - 1) {
                current = current->ptr[i + 1];
                break;
            }
        }
    }

    for (int i = 0; i < current->size; i++) {
        if (current->key[i] == x) {
            return 1;
        }
    }

    return 0;
}

void display(Node* current) {
    if (current == NULL) {
        return;
    }
    std::queue<Node*> q;
    q.push(current);
    while (!q.empty()) {
        int l;
        l = q.size();

        for (int i = 0; i < l; i++) {
            Node* tNode = q.front();
            q.pop();

            for (int j = 0; j < tNode->size; j++) {
                if (tNode != NULL) {
                    printf("%d ", tNode->key[j]);
                }
            }

            for (int j = 0; j < tNode->size + 1; j++) {
                if (tNode->ptr[j] != NULL) {
                    q.push(tNode->ptr[j]);
                }
            }
            printf("\t");
        }
        printf("\n");
    }
}

Node* findParent(Node* current, Node* child) {
    Node* parent = NULL;
    if (current->isLeaf || current->ptr[0]->isLeaf) {
        return NULL;
    }

    for (int i = 0; i < current->size + 1; i++) {
        if (current->ptr[i] == child) {
            parent = current;
            return parent;
        } else {
            parent = findParent(current->ptr[i], child);
            if (parent != NULL) {
                return parent;
            }
        }
    }
    return parent;
}

int main() {
    BPlusTree* tree = createBPlusTree();
    printf("The size of the bucket is %d!\n", bucketSize);

    // Insertions
    tree->root = createNode();
    tree->root->key[0] = 1;
    tree->root->isLeaf = true;
    tree->root->size = 1;

    Node* current = tree->root;

    Node* newNode = createNode();
    newNode->key[0] = 2;
    newNode->isLeaf = true;
    newNode->size = 1;
    current->ptr[current->size] = newNode;
    current->size++;
    display(tree->root);

    newNode = createNode();
    newNode->key[0] = 3;
    newNode->isLeaf = true;
    newNode->size = 1;
    current->ptr[current->size] = newNode;
    current->size++;
    display(tree->root);

    newNode = createNode();
    newNode->key[0] = 4;
    newNode->isLeaf = true;
    newNode->size = 1;
    current->ptr[current->size] = newNode;
    current->size++;
    display(tree->root);

    newNode = createNode();
    newNode->key[0] = 5;
    newNode->isLeaf = true;
    newNode->size = 1;
    current->ptr[current->size] = newNode;
    current->size++;
    display(tree->root);

    return 0;
}
