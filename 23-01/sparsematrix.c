#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[100][100];
int **mat,row,col,i,j,count =0;
printf("Enter the value of row is : ");
scanf("%d",&row);
mat = (int**)malloc(row*sizeof(int*));
printf("Enter the value of coloumn is : ");
scanf("%d",&col);

for(int i=0;i<row;i++){
mat[i] =(int*)malloc(col*sizeof(int));
}
printf("\nInput the matrix elememts : \n");
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
printf("The matrix elements a%d%d is : ",i+1,j+1);
scanf("%d",&arr[i][j]);
}
}
printf("\nThe martix becomes :\n ");
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
printf("%d  ",arr[i][j]);
}
printf("\n");
}
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
if(arr[i][j] == 0)
count ++;
}
}
if(count > (row*col)/2){
printf("The martix is sparse martix ");
}
else{
printf("The martix is not sparse martix ");
}
return 0;
}