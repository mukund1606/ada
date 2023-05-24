#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

#define maxSize 100

int queue[maxSize];
int front = -1;
int rear = -1;
int c = 1;

int isEmpty()
{
  return front == -1;
}

int isFull()
{
  return (rear + 1) % maxSize == front;
}

void enqueue(int data)
{
  if (isFull())
  {
    printf("Queue is full\n");
    return;
  }

  rear = (rear + 1) % maxSize;
  queue[rear] = data;

  if (front == -1)
  {
    front = rear;
  }
}

int dequeue()
{
  int item;
  if (isEmpty())
  {
    printf("Queue is empty\n");
    return -1;
  }

  item = queue[front];
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front = (front + 1) % maxSize;
  }
  return item;
}

void BFS(int **graph, int source, int numVertices)
{
  int i;
  int *visited = calloc(numVertices, sizeof(int));
  enqueue(source);
  visited[source] = 1;
  while (!isEmpty())
  {
    int temp = dequeue();
    printf("Visited %d\n", temp);
    for (i = 0; i < numVertices; i++)
    {
      if (graph[temp][i] == 1 && !visited[i])
      {
        enqueue(i);
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
  BFS(graph, i, size);
  // getch();
  // clrscr();
  return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
