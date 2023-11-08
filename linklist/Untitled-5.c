#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int row, col, value;
    struct Node* next;
};

// Function to create a new node
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

// Function to insert a node into the linked list in sorted order
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);

    if (*head == NULL || (row < (*head)->row) || (row == (*head)->row && col < (*head)->col)) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        struct Node* prev = NULL;

        while (current != NULL && (current->row < row || (current->row == row && current->col <= col))) {
            prev = current;
            current = current->next;
        }

        newNode->next = current;
        prev->next = newNode;
    }
}

// Function to add two sparse matrices
struct Node* addSparseMatrices(struct Node* matrix1, struct Node* matrix2) {
    struct Node* result = NULL;

    while (matrix1 != NULL || matrix2 != NULL) {
        if (matrix1 == NULL || (matrix2 != NULL && (matrix2->row < matrix1->row || (matrix2->row == matrix1->row && matrix2->col < matrix1->col)))) {
            insertNode(&result, matrix2->row, matrix2->col, matrix2->value);
            matrix2 = matrix2->next;
        } else if (matrix2 == NULL || (matrix1 != NULL && (matrix1->row < matrix2->row || (matrix1->row == matrix2->row && matrix1->col < matrix2->col)))) {
            insertNode(&result, matrix1->row, matrix1->col, matrix1->value);
            matrix1 = matrix1->next;
        } else {
            // Both matrices have elements at the same position
            int sum = matrix1->value + matrix2->value;
            if (sum != 0) {
                insertNode(&result, matrix1->row, matrix1->col, sum);
            }
            matrix1 = matrix1->next;
            matrix2 = matrix2->next;
        }
    }

    return result;
}

// Function to display the linked list representation of a sparse matrix
void displaySparseMatrix(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The matrix is empty.\n");
        return;
    }
    
    int maxRow = current->row;
    int maxCol = current->col;
    
    // Find the maximum row and column indices
    while (current != NULL) {
        if (current->row > maxRow) {
            maxRow = current->row;
        }
        if (current->col > maxCol) {
            maxCol = current->col;
        }
        current = current->next;
    }
    
    // Create a 2D array to represent the matrix
    int matrix[maxRow + 1][maxCol + 1];
    for (int i = 0; i <= maxRow; i++) {
        for (int j = 0; j <= maxCol; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // Populate the matrix with values from the linked list
    current = head;
    while (current != NULL) {
        matrix[current->row][current->col] = current->value;
        current = current->next;
    }
    
    // Display the matrix
    for (int i = 0; i <= maxRow; i++) {
        for (int j = 0; j <= maxCol; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Node* matrix1 = NULL;
    struct Node* matrix2 = NULL;

    int m, n;
    printf("Enter the dimensions of the matrices (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int element;
            scanf("%d", &element);
            if (element != 0) {
                insertNode(&matrix1, i, j, element);
            }
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int element;
            scanf("%d", &element);
            if (element != 0) {
                insertNode(&matrix2, i, j, element);
            }
        }
    }

    printf("Matrix 1:\n");
    displaySparseMatrix(matrix1);

    printf("\nMatrix 2:\n");
    displaySparseMatrix(matrix2);

    struct Node* result = addSparseMatrices(matrix1, matrix2);

    printf("\nResultant Matrix:\n");
    displaySparseMatrix(result);

    // Free allocated memory
    while (matrix1 != NULL) {
        struct Node* temp = matrix1;
        matrix1 = matrix1->next;
        free(temp);
    }

    while (matrix2 != NULL) {
        struct Node* temp = matrix2;
        matrix2 = matrix2->next;
        free(temp);
    }

    while (result != NULL) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
