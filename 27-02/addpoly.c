#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

void insertTerm(struct Term **head, int coefficient, int exponent);
void displayPolynomial(struct Term *head);
struct Term* addPolynomials(struct Term *poly1, struct Term *poly2);

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *result = NULL;

    int coefficient, exponent;
    char choice;

    printf("Enter polynomial 1:\n");
    do {
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);

        printf("Do you want to add another term to polynomial 1? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nEnter polynomial 2:\n");
    do {
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);

        printf("Do you want to add another term to polynomial 2? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Result of addition: ");
    displayPolynomial(result);

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

struct Term* addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    struct Term *temp = NULL;
    struct Term *prev = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        temp = (struct Term *)malloc(sizeof(struct Term));
        temp->next = NULL;

        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }

        if (poly1->exponent > poly2->exponent) {
            temp->coefficient = poly1->coefficient;
            temp->exponent = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            temp->coefficient = poly2->coefficient;
            temp->exponent = poly2->exponent;
            poly2 = poly2->next;
        } else {
            temp->coefficient = poly1->coefficient + poly2->coefficient;
            temp->exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        prev = temp;
    }

    while (poly1 != NULL) {
        temp = (struct Term *)malloc(sizeof(struct Term));
        temp->coefficient = poly1->coefficient;
        temp->exponent = poly1->exponent;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        temp = (struct Term *)malloc(sizeof(struct Term));
        temp->coefficient = poly2->coefficient;
        temp->exponent = poly2->exponent;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
        poly2 = poly2->next;
    }

    return result;
}
