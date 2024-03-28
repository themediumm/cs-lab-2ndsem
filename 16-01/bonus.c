#include<stdio.h>
int main()
{
  int a[10], i, j = 10, temp;
  printf("Enter integer numbers\n");
  for(i = 0; i < 10; i++)
      scanf("%d", &a[i]);

  for(i = 0; i <= j; i++)
    {
       if(a[i] % 2 == 0)
         {
            while(j > i)
              {
                 j--;
                    if(a[j] % 2 != 0)
                    {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                        break;
                    }
                }
            }
        }

        printf("\nAfter re-arranging even and odd elements ...\n");
        for(i = 0; i < 10; i++)
            printf("%d\n", a[i]);

        return 0;
    }