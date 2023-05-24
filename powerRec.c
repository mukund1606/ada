#include <stdio.h>

long long int power(long long int a, long long int b)
{
  if (b == 0)
    return 1;
  return a * power(a, b - 1);
}

int main()
{
  long long int a, b;
  printf("Enter the base and power: ");
  scanf("%lld %lld", &a, &b);
  printf("%lld^%lld = %lld", a, b, power(a, b));
  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)