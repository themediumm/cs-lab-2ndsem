#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList();
void displayLinkedList(struct Node *head);
struct Node *deleteFirst(struct Node *head);
struct Node *deleteLast(struct Node *head);
struct Node *deleteAtPosition(struct Node *head, int position);
struct Node *deleteAfterElement(struct Node *head, int element);

int main() {
    struct Node *head = NULL;
    int choice, position, element;

    do {
        printf("\nMenu:\n");
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Delete an element at the beginning\n");
        printf("4. Delete an element at the end\n");
        printf("5. Delete an element at a specified position\n");
        printf("6. Delete an element after a specific element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createLinkedList();
                break;
            case 2:
                displayLinkedList(head);
                break;
            case 3:
                head = deleteFirst(head);
                break;
            case 4:
                head = deleteLast(head);
                break;
            case 5:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 6:
                printf("Enter the element after which you want to delete: ");
                scanf("%d", &element);
                head = deleteAfterElement(head, element);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

struct Node *createLinkedList() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int data;
    char choice;

    do {
        printf("Enter data for the new node: ");
        scanf("%d", &data);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

void displayLinkedList(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *deleteFirst(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty. No element to delete.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    printf("First element deleted successfully.\n");

    return head;
}

struct Node *deleteLast(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty. No element to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last element deleted successfully.\n");

    return head;
}

struct Node *deleteAtPosition(struct Node *head, int position) {
    if (head == NULL) {
        printf("Linked list is empty. No element to delete.\n");
        return NULL;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    int count = 1;
    while (temp != NULL && count != position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position not found.\n");
        return head;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Element at position %d deleted successfully.\n", position);

    return head;
}

struct Node *deleteAfterElement(struct Node *head, int element) {
    if (head == NULL) {
        printf("Linked list is empty. No element to delete.\n");
        return NULL;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return head;
    }

    if (temp->next == NULL) {
        printf("No element after the specified element.\n");
        return head;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);

    printf("Element after %d deleted successfully.\n", element);

    return head;
}
