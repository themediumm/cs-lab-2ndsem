#include <stdio.h>
int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int numbers[10];
    int i;
    int max,min;


    printf("Enter 10 numbers\n");
    for (i=0; i<10; i++){
        printf("Enter Number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }

    max=min=numbers[0];
    for (i=1;i<10;i++){
        if(numbers[i]>max){
            max = numbers[i];
        }
        if(numbers[i] < min){
            min = numbers[i];
        }
    }

    printf("The maximum number is : %d\n", max);
    printf("The minimum number is : %d\n", min);

    int target;

    printf("Enter the number you want to search for : ");
        scanf("%d", &target);

    int size = sizeof(numbers)/sizeof(numbers[0]);

    int rslt = linearSearch(numbers,size,target);

    if (rslt != -1){
        printf("Element found at index: %d\n", rslt);
    }
    else {
        printf("Element not found in the given array. \n");
    }

    return 0;

}