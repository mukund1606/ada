// Write a program to find Maximum and Minimum element in an array using Iteration.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>
#include <malloc.h>

int main()
{
  int n, *a, i, min, max;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  a = calloc(n, sizeof(int));
  printf("Enter Elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  min = max = a[0];
  for (i = 0; i < n; i++)
  {
    if (a[i] < min)
    {
      min = a[i];
    }
    if (a[i] > max)
    {
      max = a[i];
    }
  }
  printf("Minimum Element: %d\n", min);
  printf("Maximum Element: %d", max);
  return 0;
}