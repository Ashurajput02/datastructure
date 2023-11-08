#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* push(struct Node* top, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int isEmpty(struct Node* top) {
    return (top == NULL);
}

int isBalanced(char expression[]) {
  
    return isEmpty(stack);
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not balanced\n");
    }

    return 0;
}
