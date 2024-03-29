#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void create(struct Stack* s) {
    s->top = NULL;
}

void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;

    printf("Element pushed successfully.\n");
}

void pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct Node* temp = s->top;
        s->top = s->top->next;
        printf("Popped element: %d\n", temp->data);
        free(temp);
    }
}

void peek(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", s->top->data);
    }
}

void update(struct Stack* s, int index, int value) {
    struct Node* current = s->top;
    int count = 0;

    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid index\n");
    } else {
        current->data = value;
        printf("Element updated successfully.\n");
    }
}

void display(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        struct Node* current = s->top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    create(&stack);

    int choice, value, index;

    do {
        printf("\n*** Stack Operations ***\n");
        printf("1. Push in stack\n");
        printf("2. Pop in stack\n");
        printf("3. Peek into stack\n");
        printf("4. Update stack\n");
        printf("5. Display stack\n");
        printf("0. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                printf("Enter the index to update: ");
                scanf("%d", &index);
                printf("Enter the new value: ");
                scanf("%d", &value);
                update(&stack, index, value);
                break;
            case 5:
                display(&stack);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
