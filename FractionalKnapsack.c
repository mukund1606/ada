// Fractional Knapsack Problem using Greedy Algorithm

#include <stdio.h>
#include <malloc.h>
#include "MergeSort.h"

void main()
{
  int n, i, j, capacity;
  struct Item *items;
  printf("Enter the number of items: ");
  scanf("%d", &n);
  items = (struct Item *)malloc(n * sizeof(struct Item));
  for (i = 0; i < n; i++)
  {
    printf("Enter the value and weight of item %d: ", i + 1);
    scanf("%d %d", &items[i].value, &items[i].weight);
  }
  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);
  mergeSort(items, 0, n - 1);
  float totalValue = 0;
  for (i = 0; i < n; i++)
  {
    if (capacity - items[i].weight >= 0)
    {
      capacity -= items[i].weight;
      totalValue += items[i].value;
    }
    else
    {
      totalValue += (float)items[i].value / items[i].weight * capacity;
      break;
    }
  }
  printf("Total value of items that can be put into the knapsack: %f\n", totalValue);
}