#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Queue {
    struct Node *front, *rear;
};


void createQueue(struct Queue *q);
void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);
int queueFront(struct Queue *q);
int queueRear(struct Queue *q);
int queueCount(struct Queue *q);
void display(struct Queue *q);

int main() {
    struct Queue q;
    createQueue(&q);

    int choice, element;

    do {
        printf("\n\n----- MENU -----\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. queueFRONT\n");
        printf("4. queueREAR\n");
        printf("5. queueCOUNT\n");
        printf("6. DISPLAY\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&q));
                break;
            case 3:
                printf("Element at front of queue: %d\n", queueFront(&q));
                break;
            case 4:
                printf("Element at rear of queue: %d\n", queueRear(&q));
                break;
            case 5:
                printf("Number of elements in queue: %d\n", queueCount(&q));
                break;
            case 6:
                display(&q);
                break;
            case 7:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 7);

    return 0;
}


void createQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}


void enqueue(struct Queue *q, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}


int dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    struct Node *temp = q->front;
    int item = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return item;
}


int queueFront(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}


int queueRear(struct Queue *q) {
    if (q->rear == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->rear->data;
}


int queueCount(struct Queue *q) {
    int count = 0;
    struct Node *current = q->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void display(struct Queue *q) {
    struct Node *current = q->front;
    if (current == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements in the queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
