#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define maxSize 100

int stack[maxSize];
int top = -1;

int isFull()
{
  if (top < maxSize)
  {
    return 0;
  }
  return 1;
}

int isEmpty()
{
  if (top == -1)
  {
    return 1;
  }
  return 0;
}

void push(int elem)
{
  if (!isFull())
  {
    stack[++top] = elem;
  }
  else
    printf("Overflow\n");
}

int pop()
{
  if (!isEmpty())
  {
    return stack[top--];
  }
  printf("Underflow\n");
  exit(1);
  return 0;
}

void DFS(int **graph, int source, int numVertices)
{
  int i;
  int *visited = calloc(numVertices, sizeof(int));
  push(source);
  visited[source] = 1;
  while (!isEmpty())
  {
    int temp = pop();
    printf("Visited %d\n", temp);
    for (i = numVertices - 1; i >= 0; i--)
    {
      if (graph[temp][i] == 1 && !visited[i])
      {
        push(i);
        visited[i] = 1;
      }
    }
  }
}

int main()
{
  int **graph, size, i, j;
  printf("Enetr Number of Vertices:");
  scanf("%d", &size);
  graph = (int **)calloc(size, sizeof(int *));
  for (i = 0; i < size; i++)
  {
    graph[i] = calloc(size, sizeof(int));
  }
  printf("Enter Graph:\n");
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }
  printf("Enter Source Vertex: ");
  scanf("%d", &i);
  DFS(graph, i, size);
  return 0;
}