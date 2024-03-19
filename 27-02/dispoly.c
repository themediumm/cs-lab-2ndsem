#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

void insertTerm(struct Term **head, int coefficient, int exponent);
void displayPolynomial(struct Term *head);

int main() {
    struct Term *poly = NULL;
    int coefficient, exponent;
    char choice;
    do {
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly, coefficient, exponent);

        printf("Do you want to add another term? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Polynomial: ");
    displayPolynomial(poly);

    return 0;
}

void insertTerm(struct Term **head, int coefficient, int exponent) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    if (*head == NULL) {
        *head = newTerm;
    } else {
        struct Term *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

void displayPolynomial(struct Term *head) {
    while (head != NULL) {
        printf("%dx^%d ", head->coefficient, head->exponent);
        if (head->next != NULL && head->next->coefficient >= 0) {
            printf("+ ");
        }
        head = head->next;
    }
    printf("\n");
}

