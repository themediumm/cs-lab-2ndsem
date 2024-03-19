#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Queue is full.\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Element dequeued: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void queueFront() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void queueRear() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Rear element: %d\n", queue[rear]);
}

int queueCount() {
    if (front == -1) {
        return 0;
    } else if (front <= rear) {
        return rear - front + 1;
    } else {
        return MAX_SIZE - front + rear + 1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i;
    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. queueFRONT\n");
        printf("4. queueREAR\n");
        printf("5. queueCOUNT\n");
        printf("6. DISPLAY\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                queueFront();
                break;
            case 4:
                queueRear();
                break;
            case 5:
                printf("Number of elements in the queue: %d\n", queueCount());
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
