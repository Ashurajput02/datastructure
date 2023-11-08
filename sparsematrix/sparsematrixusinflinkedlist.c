#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the sparse matrix
typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int row, int col, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list
void insertNode(Node **head, int row, int col, int value)
{
    Node *newNode = createNode(row, col, value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the sparse matrix
void printSparseMatrix(Node *head, int numRows, int numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int found = 0;
            Node *current = head;
            while (current != NULL)
            {
                if (current->row == i && current->col == j)
                {
                    printf("%d ", current->value);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found)
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    Node *sparseMatrix = NULL;
    int numRows, numCols;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &numCols);

    printf("Enter the elements of the matrix (row, column, value):\n");
    int row, col, value;
    while (1)
    {
        printf("Enter row, column, and value (-1 to stop): ");
        scanf("%d %d %d", &row, &col, &value);
        if (row == -1 || col == -1)
        {
            break;
        }
        insertNode(&sparseMatrix, row, col, value);
    }

    printf("\nSparse Matrix:\n");
    printSparseMatrix(sparseMatrix, numRows, numCols);

    return 0;
}


void add(int m1,int m2,int n1, int n2){
if(m1==m2 &&n1==n2){
    struct node *temp1=head1;
    struct node*temp2=head2;
    while(temp1!=NULL){
temp2=head2;
            
        while(temp2!=NULL){
            if(temp2->r==temp1->r && temp2->c==temp1->c){
                break;
            }
            temp2=temp2->next;

        }
        if(temp2!=NULL)
        temp1->data+=temp2->data;

        temp1=temp1->next;

    }
}
}
