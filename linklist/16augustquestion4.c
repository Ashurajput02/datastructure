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

// Function to transpose a sparse matrix represented as a linked list
struct Node* transposeSparseMatrix(struct Node* matrix, int* numRows, int* numCols) {
    if (matrix == NULL) {
        *numRows = 0;
        *numCols = 0;
        return NULL; // Transposed matrix is also empty
    }

    // Find the number of rows and columns in the original matrix
    int maxRow = matrix->row;
    int maxCol = matrix->col;
    struct Node* current = matrix;
    while (current != NULL) {
        if (current->row > maxRow) {
            maxRow = current->row;
        }
        if (current->col > maxCol) {
            maxCol = current->col;
        }
        current = current->next;
    }

    *numRows = maxCol + 1;
    *numCols = maxRow + 1;

    // Create a new linked list for the transposed matrix
    struct Node* transposedMatrix = NULL;

    // Iterate through the original matrix and insert nodes into the transposed matrix
    current = matrix;
    while (current != NULL) {
        insertNode(&transposedMatrix, current->col, current->row, current->value);
        current = current->next;
    }

    return transposedMatrix;
}

// Function to display the linked list representation of a sparse matrix
void displaySparseMatrix(struct Node* head, int numRows, int numCols) {
    struct Node* current = head;

    // Create a 2D array to represent the matrix
    int matrix[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = 0;
        }
    }

    // Populate the matrix with values from the linked list
    while (current != NULL) {
        matrix[current->row][current->col] = current->value;
        current = current->next;
    }

    // Display the transposed matrix
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Node* matrix = NULL;
    int numRows, numCols;

    printf("Enter the dimensions of the matrix (numRows numCols): ");
    scanf("%d %d", &numRows, &numCols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int element;
            scanf("%d", &element);
            if (element != 0) {
                insertNode(&matrix, i, j, element);
            }
        }
    }

    printf("Original Matrix:\n");
    displaySparseMatrix(matrix, numRows, numCols);

    struct Node* transposedMatrix = transposeSparseMatrix(matrix, &numCols, &numRows);

    printf("\nTransposed Matrix:\n");
    displaySparseMatrix(transposedMatrix, numCols, numRows);

    // Free allocated memory
    while (matrix != NULL) {
        struct Node* temp = matrix;
        matrix = matrix->next;
        free(temp);
    }

    while (transposedMatrix != NULL) {
        struct Node* temp = transposedMatrix;
        transposedMatrix = transposedMatrix->next;
        free(temp);
    }

    return 0;
}
