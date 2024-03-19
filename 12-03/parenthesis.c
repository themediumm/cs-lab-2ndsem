#include <stdio.h>
#include <stdlib.h>

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
int areParenthesesBalanced(char *exp) {
    struct Stack s;
    initialize(&s);
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            
            if (isEmpty(&s)) {
                return 0;
            }
            char popped = pop(&s);
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == ']' && popped != '[') ||
                (exp[i] == '}' && popped != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

void main() {
    char exp[MAX_SIZE];

    printf("Enter expression with parentheses: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    if (areParenthesesBalanced(exp)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }
}
    