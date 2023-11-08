#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* link;
};

struct node* head;

void push(char x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = head;
    head = temp;
}

void pop() {
    if (head == NULL) {
        printf("Nothing to pop out\n");
        return;
    }

    struct node* temp = head;
    head = head->link;
    free(temp);
}

void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->link;
    }
}

int isempty() {
    return head == NULL;
}

int isfull() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int full = temp == NULL;
    free(temp);
    return full;
}

char front() {
    return head->data;
}

int main() {
    printf("Enter length of string: ");
    int length;
    scanf("%d", &length);

    printf("Enter the string: ");
    char str[length + 1];
    scanf("%s", str);

    for (int i = 0; i < length; i++) {
        push(str[i]);
    }

    int isPalindrome = 1;

    for (int i = 0; i < length; i++) {
        char ch = front();
        pop();

        if (str[i] != ch) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}
