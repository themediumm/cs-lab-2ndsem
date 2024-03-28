#include<stdio.h>
#include<stdlib.h>
void main()
{
 int bin[10],i,j,d,s=0,k;
 printf("enter 10 decimal numbers\n");
 for(i=0;i<10;i++)
 {
  scanf("%d",&bin[i]);
 }
 for(j=0;j<10;j++)
 {
  k=bin[j];
  while(k>0)
  {
   d=k%2;
   s=s*10 + d;
   k=k/2;
  }
  printf("binaries are:%d\n",s);
  s=0;
  k=0;
 }
}
