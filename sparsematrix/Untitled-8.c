#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with n nodes
struct Node* createLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        
        struct Node* newNode = createNode(data);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

// Function to fold the linked list in a zigzag manner
void foldZigZag(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Nothing to fold
    }
    
    struct Node* slow = *head;
    struct Node* fast = (*head)->next;
    
    // Move slow and fast pointers to find the midpoint
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    // Split the list into two halves
    struct Node* secondHalf = slow->next;
    slow->next = NULL;
    
    // Reverse the second half of the list
    struct Node* prev = NULL;
    struct Node* current = secondHalf;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    secondHalf = prev;
    
    // Merge the two halves in zigzag manner
    struct Node* firstCurrent = *head;
    struct Node* secondCurrent = secondHalf;
    
    while (secondCurrent != NULL) {
        struct Node* firstNext = firstCurrent->next;
        struct Node* secondNext = secondCurrent->next;
        
        firstCurrent->next = secondCurrent;
        secondCurrent->next = firstNext;
        
        firstCurrent = firstNext;
        secondCurrent = secondNext;
    }
}

// Function to multiply overlapping nodes and display the result
void multiplyOverlappingNodes(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        head->data *= head->next->data;
        head = head->next->next;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    struct Node* head = createLinkedList(n);
    
    printf("Original Linked List: ");
    displayList(head);
    
    foldZigZag(&head);
    
    printf("Zigzag Folded Linked List: ");
    displayList(head);
    
    multiplyOverlappingNodes(head);
    
    printf("Result after multiplying overlapping nodes: ");
    displayList(head);
    
    return 0;
}
