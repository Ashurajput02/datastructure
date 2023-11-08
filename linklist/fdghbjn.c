#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}
void addTerm(struct Node** head, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display a polynomial linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("(%dx^%d) ", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, int coef2[], int exp2[], int terms2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    int i;

    while (temp1 != NULL) {
        addTerm(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    for (i = 0; i < terms2; i++) {
        addTerm(&result, coef2[i], exp2[i]);
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    int coef2[] = {3, 4, 2};
    int exp2[] = {3, 1, 0};
    int terms2 = sizeof(coef2) / sizeof(coef2[0]);

    // Creating linked list for the first polynomial
    addTerm(&poly1, 5, 4);
    addTerm(&poly1, 2, 2);
    addTerm(&poly1, 7, 1);
    addTerm(&poly1, 3, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    for (int i = 0; i < terms2; i++) {
        printf("(%dx^%d) ", coef2[i], exp2[i]);
        if (i < terms2 - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    struct Node* result = addPolynomials(poly1, coef2, exp2, terms2);
    printf("Result: ");
    display(result);

    return 0;
}
