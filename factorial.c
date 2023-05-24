#include <stdio.h>

int factorial(int num);

int main()
{
  int num, fact;
  printf("Enter Number: ");
  scanf("%d", &num);
  fact = factorial(num);
  printf("Factorial of %d is %d", num, fact);
  return 0;
}

int factorial(int num)
{
  if (num == 0)
  {
    return 1;
  }
  return num * factorial(num - 1);
}