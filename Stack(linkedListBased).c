#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

int main() {
    struct Stack* stack = createStack();
    printf("Before pushing, Empty: %d\n", isEmpty(stack));
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("After pushing, Empty: %d\n", isEmpty(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("After popping, Empty: %d\n", isEmpty(stack));
    return 0;
}
