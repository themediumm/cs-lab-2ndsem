#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};


void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);
int queueFront(struct Queue *q);
int queueRear(struct Queue *q);
int queueCount(struct Queue *q);
void display(struct Queue *q);

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

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


void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}


int dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}


int queueFront(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}


int queueRear(struct Queue *q) {
    if (q->rear == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->rear];
}


int queueCount(struct Queue *q) {
    if (q->front == -1)
        return 0;
    return q->rear - q->front + 1;
}


void display(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
