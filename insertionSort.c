#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n, *a, b, i, j;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  a = calloc(n, sizeof(int));
  printf("Enter the elements of the array: ");
  for (i = 0; i < n; i++)
  {

    scanf("%d", &b);
    if (i == 0)
    {
      a[i] = b;
    }
    else
    {
      j = i - 1;
      while (j >= 0 && a[j] > b)
      {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = b;
    }
  }
  printf("The sorted array is: ");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
}