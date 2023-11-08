#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* child;
};

Node* head = nullptr;

Node* createNode(int x) {
    Node* temp = new Node();
    temp->value = x;
    temp->child = nullptr;
    temp->next = nullptr;
    return temp;
}

void createNode(int u, int v, int type) {
    Node* ptr1 = nullptr;
    Node* ptr2 = nullptr;
    Node* temp = head;

    // Find nodes with values u and v
    while (temp != nullptr) {
        if (temp->value == u) {
            ptr1 = temp;
        }
        if (temp->value == v) {
            ptr2 = temp;
        }
        temp = temp->next;
    }

    // Create new nodes if not found
    if (ptr1 == nullptr) {
        ptr1 = createNode(u);
    }
    if (ptr2 == nullptr) {
        ptr2 = createNode(v);
    }

    // Link child or next based on type
    if (type == 0) {
        ptr1->next = ptr2;
    } else if (type == 1) {
        ptr1->child = ptr2;
    }

    // Update head if needed
    if (head == nullptr) {
        head = ptr1;
    }
}

void printList(Node* start) {
    while (start != nullptr) {
        cout << start->value << " ";
        if (start->child != nullptr) {
            printList(start->child);
        }
        start = start->next;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        head = nullptr; // Reset head for each test case
        for (int i = 0; i < n - 1; i++) {
            int u, v, type;
            cin >> u >> v >> type;
            createNode(u, v, type);
        }
        printList(head);
        cout << endl;
    }
    return 0;
}
    