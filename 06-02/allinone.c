#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value);
struct Node* insertAtEnd(struct Node* head, int value);
struct Node* insertAtLocation(struct Node* head, int value, int location);
struct Node* insertAfterElement(struct Node* head, int element, int value);
void displayForward(struct Node* head);
void displayBackward(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value, location, element;

    do {
        printf("\nMenu\n");
        printf("1. Insert Element at Beginning\n");
        printf("2. Insert Element at End\n");
        printf("3. Insert Element at Location\n");
        printf("4. Insert Element After Specific Element\n");
        printf("5. Display Elements from Beginning to End\n");
        printf("6. Display Elements from End to Beginning\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the location to insert: ");
                scanf("%d", &location);
                head = insertAtLocation(head, value, location);
                break;
            case 4:
                printf("Enter the element to insert after: ");
                scanf("%d", &element);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAfterElement(head, element, value);
                break;
            case 5:
                displayForward(head);
                break;
            case 6:
                displayBackward(head);
                break;
            case 7:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Element inserted successfully at the beginning.\n");

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Element inserted successfully at the end.\n");

    return head;
}

struct Node* insertAtLocation(struct Node* head, int value, int location) {
    int count = 1;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (location == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current != NULL && count < location - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid location!\n");
            free(newNode);
            return head;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Element inserted successfully at location %d.\n", location);

    return head;
}

struct Node* insertAfterElement(struct Node* head, int element, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    struct Node* current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;

    printf("Element inserted successfully after %d.\n", element);

    return head;
}

void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Linked List (Forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    int data[1000], count = 0;
    while (current != NULL) {
        data[count] = current->data;
        current = current->next;
        count++;
    }
    printf("Linked List (Backward): ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d -> ", data[i]);
    }
    printf("NULL\n");
}
