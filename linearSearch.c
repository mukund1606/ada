#include <stdio.h>
#include <malloc.h>
int main()
{
  int *a, n, i, elem, flag = 0;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  a = calloc(n, sizeof(int));
  printf("Enter Elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter Element to Search:");
  scanf("%d", &elem);
  for (i = 0; i < n; i++)
  {
    if (a[i] == elem)
    {
      printf("Element Found at %d", i);
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    printf("Element Not Found");
  return 0;
}