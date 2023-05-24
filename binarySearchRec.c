#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *a, int li, int ui, int elem)
{
  int mid;
  if (li <= ui)
  {
    mid = (li + ui) / 2;
    if (a[mid] == elem)
    {
      return mid;
    }
    else if (a[mid] > elem)
    {
      ui = mid - 1;
      return binarySearch(a, li, ui, elem);
    }
    else
    {
      li = mid + 1;
      return binarySearch(a, li, ui, elem);
    }
  }
  return -1;
}

void main()
{
  int n, *a, elem;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  a = calloc(n, sizeof(int));
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Enter the element to be searched: ");
  scanf("%d", &elem);
  int pos = binarySearch(a, 0, n - 1, elem);
  if (pos == -1)
    printf("Element not found");
  else
    printf("Element found at position %d", pos + 1);
}