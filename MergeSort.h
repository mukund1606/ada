#include <stdio.h>
#include <stdlib.h>

struct Item
{
  int value;
  int weight;
};

int i;

void mergePart(struct Item *a, int FI, int mid, int LI)
{
  int j = mid + 1;
  int k = FI - 1;
  struct Item *b;
  i = FI;
  b = (struct Item *)malloc((LI + 1) * sizeof(struct Item));
  while (i <= mid && j <= LI)
  {
    if ((float)a[j].value / a[j].weight > (float)a[i].value / a[i].weight)
    {
      k++;
      b[k] = a[j];
      j++;
    }
    else
    {
      k++;
      b[k] = a[i];
      i++;
    }
  }
  if (i > mid)
  {
    while (j <= LI)
    {
      k++;
      b[k] = a[j];
      j++;
    }
  }
  else
  {
    while (i <= mid)
    {
      k++;
      b[k] = a[i];
      i++;
    }
  }
  for (i = FI; i <= LI; i++)
  {
    a[i] = b[i];
  }
}

void mergeSort(struct Item *a, int FI, int LI)
{
  int mid;
  if (FI < LI)
  {
    mid = (LI + FI) / 2;
    mergeSort(a, FI, mid);
    mergeSort(a, mid + 1, LI);
    mergePart(a, FI, mid, LI);
  }
}