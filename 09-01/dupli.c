#include <stdio.h>
int main()
{
    int n, count = 0;
    printf("Enter number of elements in the array: \n");
    scanf("%d", &n);
    int arr[n], temp[n];


    if(n==0)
    {
        printf("No element inside the array.");
        return(0);
    }


    printf("Enter elements in the array: \n");


    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    printf("\nArray Before Removing Duplicates: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < count; j++)
        {
          if (arr[i] == temp[j])
            break;
        }
        if (j == count)
        {
          temp[count] = arr[i];
          count++;
        }
    }




    printf("\nArray After  Removing Duplicates: ");



    for (int i = 0; i < count; i++){
        printf("%d ", temp[i]);
    }   
    
    
    return 0;
}