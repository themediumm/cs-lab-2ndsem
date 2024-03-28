#include <stdio.h>

void insertElement(int arr[], int size, int location, int element) {
    if (size >= 100) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    if (location < 1 || location > size + 1) {
        printf("Invalid location to insert element. Please choose a location between 1 and %d.\n", size + 1);
        return;
    }

    for (int i = size; i >= location; i--) {
        arr[i] = arr[i - 1];
    }

    arr[location - 1] = element;
    size++;
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size, location, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid array size. Please enter a size between 1 and 100.\n");
        return 1;
    }

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the location to insert element: ");
    scanf("%d", &location);

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    insertElement(arr, size, location, element);

    printf("Array after insertion:\n");
    displayArray(arr, size + 1);

    return 0;
}
