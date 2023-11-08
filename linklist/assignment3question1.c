#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row, col, value;
    struct Node* next;
};

struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void displaySparseMatrix(struct Node* head) {
    struct Node* current = head;
    printf("Row\tColumn\tValue\n");
    while (current != NULL) {
        printf("%d\t%d\t%d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    struct Node* head = NULL;

    printf("Enter the elements of the sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int element;
            scanf("%d", &element);
            if (element != 0) {
                insertNode(&head, i, j, element);
            }
        }
    }

    printf("Sparse Matrix Representation:\n");
    displaySparseMatrix(head);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
