#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the beginning of the linked list
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to swap the data of two nodes
void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the linked list using bubble sort algorithm
void sortList(Node* head) {
    Node* temp1;
    Node* temp2;
    for (temp1 = head; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->data > temp2->data) {
                swapData(temp1, temp2);
            }
        }
    }
}

int main() {
    // Create a linked list
    Node* head = NULL;
    insert(&head, 6);
    insert(&head, 3);
    insert(&head, 9);
    insert(&head, 1);
    insert(&head, 8);

    // Print the unsorted linked list
    printf("Unsorted Linked List: ");
    printList(head);

    // Sort the linked list
    sortList(head);

    // Print the sorted linked list
    printf("Sorted Linked List: ");
    printList(head);

    remove(head);
    printList(head);

    return 0;
}

void remove( Node*head){
 Node*temp1=NULL;
 while(temp1->next!=NULL)
 {
    Node *temp2=temp1->next;
    if(temp1->data==temp2->data)
    {
        temp1->next=temp2->next;
        free(temp2);
    }
    temp1=temp1->next;
 }
}
