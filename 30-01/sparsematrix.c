#include <stdio.h>

int row;

int main(){

    ENTER_AGAIN:

    printf("input the number of rows square matrix: ");
    scanf("%d", &row);

    int array[row][row];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            printf("input the element index #%d %d: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            if( i - j > 1 && j - i > 1 && array[i][j] != 0){
                printf("the input matrix is not a tri-diagonal sparse matrix. Please enter it again.\n");
                goto ENTER_AGAIN;
            }
        }
    }
    
    int k = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            if(array[i][j] != 0){
                k++;
            }
        }
    }

    int sparse[3][k];
    for(int i = 0, count = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            if(array[i][j] != 0){
                sparse[0][count] = i;
                sparse[1][count] = j;
                sparse[2][count] = array[i][j];
                count++; 
            }
        }
    }
    printf("hence the matrix looks like: \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for(int i = 0; i < 3; i++, printf("\n")){
        for(int j = 0; j < k; j++){
            printf("%d\t", sparse[i][j]);
        }
    }

}