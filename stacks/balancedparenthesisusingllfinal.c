#include <stdlib.h>
#include <stdio.h>

struct node {
    char data;
    struct node *link;
};

struct node* push(struct node *head, char x) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow\n");
        return head;
    }
    temp->data = x;
    temp->link = head;
    head = temp;
    return head;
}

char pop(struct node **head) {
    if (*head == NULL) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char k = (*head)->data;
    *head = (*head)->link;
    return k;
}

char top(struct node* head) {
    if (head == NULL) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char k = head->data;
    return k;
}

int isempty(struct node* head) {
    if (head == NULL)
        return 1;
    else
        return 0;
}

void printer(struct node* head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int n;
    char arr[1000];
    printf("Enter the expression: ");
    scanf("%s", arr);
    int i=0;
    while(arr[i]!='\0') {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
            head = push(head, arr[i]);
        else if (arr[i] == ')') {
            if (top(head) == '(')
                pop(&head);
            else {
                printf("Not balanced\n");
                return 0;
            }
        } else if (arr[i] == ']') {
            if (top(head) == '[')
                pop(&head);
            else {
                printf("Not balanced\n");
                return 0;
            }
        } else if (arr[i] == '}') {
            if (top(head) == '{')
                pop(&head);
            else {
                printf("Not balanced\n");
                return 0;
            }
        }
        i++;
    }
    if (isempty(head))
        printf("Balanced\n");
    else
        printf("Not balanced\n");
    return 0;
}
