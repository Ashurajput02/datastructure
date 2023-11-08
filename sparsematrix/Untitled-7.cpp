#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

void appendNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void createLinkedList(Node*& head, int u, int v, int type) {
    Node* uNode = nullptr;
    Node* vNode = nullptr;
    
    // Find or create nodes for u and v
    Node* current = head;
    while (current) {
        if (current->data == u) {
            uNode = current;
        }
        if (current->data == v) {
            vNode = current;
        }
        current = current->next;
    }
    
    if (!uNode) {
        appendNode(head, u);
        uNode = head;
    }
    
    if (!vNode) {
        appendNode(head, v);
        vNode = head;
    }
    
    // Join nodes based on type
    if (type == 0) {
        uNode->next = vNode;
    } else if (type == 1) {
        uNode->child = vNode;
    }
}

void printLinkedList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    
    // Example usage
    createLinkedList(head, 4, 7, 1);
    createLinkedList(head, 7, 3, 0);
    createLinkedList(head, 4, 5, 0);
    
    printLinkedList(head); // Output: 4 5 7 3
    return 0;
}
