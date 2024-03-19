#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
struct Stack {
    int top;
    int items[MAX_SIZE];
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
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}
int evaluatePostfix(char *exp) {
    struct Stack s;
    initialize(&s);

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}