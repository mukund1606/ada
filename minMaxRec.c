// Write a program to find Maximum and Minimum element in an array using Recursion.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

int min(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  else if (arr[n - 1] > min(arr, n - 1))
    return min(arr, n - 1);
  else
    return arr[n - 1];
}

int max(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  else if (arr[n - 1] < max(arr, n - 1))
    return max(arr, n - 1);
  else
    return arr[n - 1];
}

int main()
{
  int *arr, n, i;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  arr = malloc(n * sizeof(int));
  printf("Enter the elements of array: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printf("Maximum element is %d", max(arr, n));
  printf("Minimum element is %d", min(arr, n));
  return 0;
}