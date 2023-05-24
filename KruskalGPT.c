#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct Edge
{
  int src;
  int dest;
  int weight;
} Edge;

typedef struct Graph
{
  int numVertices;
  Edge *edges;
} Graph;

typedef struct Subset
{
  int parent;
  int rank;
} Subset;

Edge createEdge(int src, int dest, int weight)
{
  Edge newEdge;
  newEdge.src = src;
  newEdge.dest = dest;
  newEdge.weight = weight;
  return newEdge;
}

Graph *createGraph(int numVertices, int numEdges)
{
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->edges = malloc(numEdges * sizeof(Edge));
  return graph;
}

int find(Subset *subsets, int i)
{
  if (subsets[i].parent != i)
  {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

void unionSet(Subset *subsets, int x, int y)
{
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);
  if (subsets[xroot].rank < subsets[yroot].rank)
  {
    subsets[xroot].parent = yroot;
  }
  else if (subsets[xroot].rank > subsets[yroot].rank)
  {
    subsets[yroot].parent = xroot;
  }
  else
  {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int compareEdges(const void *a, const void *b)
{
  Edge *edgeA = (Edge *)a;
  Edge *edgeB = (Edge *)b;
  return edgeA->weight - edgeB->weight;
}

void kruskalMST(Graph *graph)
{
  int numVertices = graph->numVertices;
  Edge *result = malloc((numVertices - 1) * sizeof(Edge));
  Subset *subsets = malloc(numVertices * sizeof(Subset));
  for (int i = 0; i < numVertices; i++)
  {
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }
  qsort(graph->edges, numVertices * (numVertices - 1) / 2, sizeof(Edge), compareEdges);
  int i = 0, e = 0;
  while (e < numVertices - 1 && i < numVertices * (numVertices - 1) / 2)
  {
    Edge nextEdge = graph->edges[i++];
    int x = find(subsets, nextEdge.src);
    int y = find(subsets, nextEdge.dest);
    if (x != y)
    {
      result[e++] = nextEdge;
      unionSet(subsets, x, y);
    }
  }
  printf("Edge : Weight\n");
  for (int i = 0; i < numVertices - 1; i++)
  {
    printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
  }
}

int main()
{
  int numVertices;
  printf("Enter Number of Vertices: ");
  scanf("%d", &numVertices);
  Graph *graph = createGraph(numVertices, numVertices * (numVertices - 1) / 2);
  printf("Enter Graph:\n");
  int count = 0;
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = i + 1; j < numVertices; j++)
    {
      int weight;
      scanf("%d", &weight);
      if (weight != 0)
      {
        graph->edges[count++] = createEdge(i, j, weight);
      }
    }
  }
  kruskalMST(graph);
  return 0;
}