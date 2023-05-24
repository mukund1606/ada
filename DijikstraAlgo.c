// To implement the Dijkstra's algorithm using Greedy Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **createGraph(int n)
{
  int **G, i, j;
  G = (int **)calloc(n, sizeof(int *));
  for (i = 0; i < n; i++)
  {
    G[i] = (int *)calloc(n, sizeof(int));
  }
  for (i = 0; i < n; i++)
  {
    printf("Enter Weight of %d Vertex (0 if Not Connected):", i);
    for (j = 0; j < n; j++)
    {
      scanf("%d", &G[i][j]);
    }
  }
  return G;
}

void disp(int n, int **G)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

int minDistance(int dist[], int sptSet[], int V)
{
  int min = __INT_MAX__, min_index, v;
  for (v = 0; v < V; v++)
  {
    if (sptSet[v] == 0 && dist[v] <= min)
    {
      min = dist[v], min_index = v;
    }
  }
  return min_index;
}

void printSolution(int dist[], int V)
{
  printf("Vertex \t\t Distance from Source \n");
  for (int i = 0; i < V; i++)
  {
    printf("%d \t\t %d \n", i, dist[i]);
  }
}

void dijkstra(int **G, int V, int src)
{
  int dist[V];   // The output array. dist[i] will hold the shortest distance from src to i
  int sptSet[V]; // Array to store if the vertex is included in the shortest path tree
  int i, u, v;
  for (i = 0; i < V; i++)
  {
    dist[i] = __INT_MAX__, sptSet[i] = 0;
  }
  dist[src] = 0;
  for (i = 0; i < V - 1; i++)
  {
    u = minDistance(dist, sptSet, V);
    sptSet[u] = 1;
    for (v = 0; v < V; v++)
    {
      if (!sptSet[v] && G[u][v] && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v])
      {
        dist[v] = dist[u] + G[u][v];
      }
    }
  }
  printSolution(dist, V);
}

int main()
{
  int **G, V, i, j, src;
  printf("Enter Number of Vertices:");
  scanf("%d", &V);
  G = createGraph(V);
  printf("Enter Source Vertex:");
  scanf("%d", &src);
  dijkstra(G, V, src);
  return 0;
}
