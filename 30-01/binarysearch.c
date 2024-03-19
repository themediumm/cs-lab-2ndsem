#include <stdio.h>

void quickSort(int arr[], int low, int high);
void displayArray(int arr[], int size);
int binarySearchRecursive(int arr[], int low, int high, int key);
int binarySearchIterative(int arr[], int size, int key);

int main() {
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    displayArray(arr, size);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int recursiveResult = binarySearchRecursive(arr, 0, size - 1, key);
    if (recursiveResult != -1) {
        printf("Element %d found at index (recursive): %d\n", key, recursiveResult);
    } else {
        printf("Element %d not found (recursive)\n", key);
    }

    int iterativeResult = binarySearchIterative(arr, size, key);
    if (iterativeResult != -1) {
        printf("Element %d found at index (iterative): %d\n", key, iterativeResult);
    } else {
        printf("Element %d not found (iterative)\n", key);
    }

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }

        return binarySearchRecursive(arr, mid + 1, high, key);
    }

    return -1;
}

int binarySearchIterative(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}
