#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct LinkedList {
    struct Node *head;
};



void append(struct LinkedList *list, int data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;


    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    
    struct Node *last_node = list->head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    
}


void print_list(struct LinkedList *list) {
    struct Node *current_node = list->head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}


int main() {
    struct LinkedList list = {NULL};

    append(&list, 1);
    append(&list, 2);
    append(&list, 3);

    print_list(&list);

    return 0;
}
