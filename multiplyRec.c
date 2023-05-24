// Write a program to find product of two numbers using recursion.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>

int multiply(int a, int b)
{
  if (b == 0)
    return 0;
  else if (b == 1)
    return a;
  return a + multiply(a, b - 1);
}

int main()
{
  int a, b;
  printf("Enter the two numbers: ");
  scanf("%d %d", &a, &b);
  printf("%d*%d = %d", a, b, multiply(a, b));
  return 0;
}
