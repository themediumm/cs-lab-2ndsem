#include <stdio.h>

int main() {
    int size,size2;

    // Input the size of the square array
    printf("Enter the number of rows the array will have: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size\n");
        return 1;
    }
    printf("Enter the number of columns the array will have: ");
    scanf("%d", &size2);

    if (size2 <= 0) {
        printf("Invalid array size\n");
        return 1;
    }
    
    if (size != size2){
        printf("The given array is not having equal number of rows and columns.\n");

        return 0;
    }

    int arr[size][size];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter element arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the array
    printf("\nThe entered 2D array is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Calculate and print the sum of diagonals
    int leftDiagonalSum = 0, rightDiagonalSum = 0;
    for (int i = 0; i < size; i++) {
        leftDiagonalSum += arr[i][i];
        rightDiagonalSum += arr[i][size - 1 - i];
    }

    // Print the sums
    printf("Sum of left diagonal: %d\n", leftDiagonalSum);
    printf("Sum of right diagonal: %d\n", rightDiagonalSum);

    return 0;
}
