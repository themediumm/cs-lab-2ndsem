#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtLocation(struct Node* head, int value, int location);
void display(struct Node* head);
int countNodes(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value, location;

    do {
        printf("\nMenu\n");
        printf("1. Insert Element at Location\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the location to insert: ");
                scanf("%d", &location);
                head = insertAtLocation(head, value, location);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

struct Node* insertAtLocation(struct Node* head, int value, int location) {
    int count = countNodes(head);

    if (location < 1 || location > count + 1) {
        printf("Invalid location!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    if (location == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        for (int i = 1; i < location - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Element inserted successfully at location %d.\n", location);

    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
