// Write a program to find GCD of two numbers using recursion.
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))

#include <stdio.h>

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  int a, b;
  printf("Enter the two numbers: ");
  scanf("%d %d", &a, &b);
  printf("GCD of %d and %d is %d", a, b, gcd(a, b));
  return 0;
}
