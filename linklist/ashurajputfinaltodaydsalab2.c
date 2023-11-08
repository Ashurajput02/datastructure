#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coef;
    newNode->exp = exp;
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

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("(%dx^%d) ", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, int coef2[], int exp2[], int terms2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    int i;

    while (temp1 != NULL) {
        addTerm(&result, temp1->coeff, temp1->exp);
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

    printf("Enter terms for Polynomial 1 (enter 0 coefficient to end):\n");
    int coef1, exp1;
    while (1) {
        printf("Coefficient: ");
        scanf("%d", &coef1);
        if (coef1 == 0) {
            break;
        }
        printf("Exponent: ");
        scanf("%d", &exp1);
        addTerm(&poly1, coef1, exp1);
    }

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &terms2);
    int coefInput, expInput;
    for (int i = 0; i < terms2; i++) {
        printf("Coefficient for term %d: ", i + 1);
        scanf("%d", &coefInput);
        printf("Exponent for term %d: ", i + 1);
        scanf("%d", &expInput);
        coef2[i] = coefInput;
        exp2[i] = expInput;
    }

    printf("\nPolynomial 1: ");
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
