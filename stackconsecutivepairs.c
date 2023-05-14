#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int value = stack[top];
    top--;
    return value;
}

bool check_consecutive_pairs() {
    if (top < 1) {
        return true;
    }
    if (top % 2 != 0) {
        pop();
    }
    bool is_consecutive = true;
    for (int i = 0; i < top; i += 2) {
        if (abs(stack[i] - stack[i+1]) != 1) {
            is_consecutive = false;
            break;
        }
    }
    return is_consecutive;
}

int main() {
    push(4);
    push(5);
    push(-2);
    push(-3);
    push(11);
    push(10);
    push(5);
    push(6);
    push(20);

    bool result = check_consecutive_pairs();
    printf("%s\n", result ? "True" : "False");

    return 0;
}
