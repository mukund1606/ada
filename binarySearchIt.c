#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n, *a, elem, flag, li, ui, mid;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  a = calloc(n, sizeof(int));
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Enter the element to be searched: ");
  scanf("%d", &elem);
  li = 0;
  ui = n - 1;
  while (li <= ui)
  {
    mid = (li + ui) / 2;
    if (a[mid] == elem)
    {
      flag = 1;
      break;
    }
    else if (a[mid] > elem)
      ui = mid - 1;
    else
      li = mid + 1;
  }
  if (flag == 1)
    printf("Element found at position %d", mid + 1);
  else
    printf("Element not found");
}