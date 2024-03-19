#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
struct Stack {
    int top;
    char items[MAX_SIZE];
};
void initialize(struct Stack *s) {
    s->top = -1;
}
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}
void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void infixToPostfix(char *infix, char *postfix) {
    struct Stack s;
    initialize(&s);

    int i = 0; 
    int j = 0; 
    while (infix[i]) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(') {
            push(&s, infix[i++]);
        }
        else if (infix[i] == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.items[s.top] != '(') {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&s);
            }
            i++;
        }
        else {
            while (!isEmpty(&s) && precedence(infix[i]) <= precedence(s.items[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}