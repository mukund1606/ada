#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct Edge
{
  int dest;
  int weight;
  struct Edge *next;
} Edge;

typedef struct Graph
{
  int numVertices;
  Edge **adjLists;
} Graph;

typedef struct MinHeapNode
{
  int vertex;
  int key;
} MinHeapNode;

typedef struct MinHeap
{
  int size;
  int capacity;
  int *pos;
  MinHeapNode **array;
} MinHeap;

Edge *createEdge(int dest, int weight)
{
  Edge *newEdge = malloc(sizeof(Edge));
  newEdge->dest = dest;
  newEdge->weight = weight;
  newEdge->next = NULL;
  return newEdge;
}

Graph *createGraph(int numVertices)
{
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjLists = malloc(numVertices * sizeof(Edge *));
  for (int i = 0; i < numVertices; i++)
  {
    graph->adjLists[i] = NULL;
  }
  return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight)
{
  Edge *newEdge = createEdge(dest, weight);
  newEdge->next = graph->adjLists[src];
  graph->adjLists[src] = newEdge;
}

MinHeapNode *createMinHeapNode(int vertex, int key)
{
  MinHeapNode *node = malloc(sizeof(MinHeapNode));
  node->vertex = vertex;
  node->key = key;
  return node;
}

MinHeap *createMinHeap(int capacity)
{
  MinHeap *heap = malloc(sizeof(MinHeap));
  heap->size = 0;
  heap->capacity = capacity;
  heap->pos = malloc(capacity * sizeof(int));
  heap->array = malloc(capacity * sizeof(MinHeapNode *));
  return heap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
  MinHeapNode *temp = *a;
  *a = *b;
  *b = temp;
}

void minHeapify(MinHeap *heap, int idx)
{
  int smallest, left, right;
  smallest = idx;
  left = 2 * idx + 1;
  right = 2 * idx + 2;
  if (left < heap->size && heap->array[left]->key < heap->array[smallest]->key)
  {
    smallest = left;
  }
  if (right < heap->size && heap->array[right]->key < heap->array[smallest]->key)
  {
    smallest = right;
  }
  if (smallest != idx)
  {
    MinHeapNode *smallestNode = heap->array[smallest];
    MinHeapNode *idxNode = heap->array[idx];
    heap->pos[smallestNode->vertex] = idx;
    heap->pos[idxNode->vertex] = smallest;
    swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
    minHeapify(heap, smallest);
  }
}

bool isEmpty(MinHeap *heap)
{
  return heap->size == 0;
}

MinHeapNode *extractMin(MinHeap *heap)
{
  if (isEmpty(heap))
  {
    return NULL;
  }
  MinHeapNode *root = heap->array[0];
  MinHeapNode *lastNode = heap->array[heap->size - 1];
  heap->array[0] = lastNode;
  heap->pos[root->vertex] = heap->size - 1;
  heap->pos[lastNode->vertex] = 0;
  heap->size--;
  minHeapify(heap, 0);
  return root;
}

void decreaseKey(MinHeap *heap, int vertex, int key)
{
  int i = heap->pos[vertex];
  heap->array[i]->key = key;
  while (i && heap->array[i]->key < heap->array[(i - 1) / 2]->key)
  {
    heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
    heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
    swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

bool isInMinHeap(MinHeap *heap, int vertex)
{
  return heap->pos[vertex] < heap->size;
}

void printMST(int *parent, int **graph, int numVertices)
{
  printf("Edge : Weight\n");
  for (int i = 1; i < numVertices; i++)
  {
    printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
  }
}

void primMST(Graph *graph)
{
  int numVertices = graph->numVertices;
  int *parent = malloc(numVertices * sizeof(int));
  int *key = malloc(numVertices * sizeof(int));
  bool *inMST = malloc(numVertices * sizeof(bool));
  MinHeap *heap = createMinHeap(numVertices);
  for (int i = 0; i < numVertices; i++)
  {
    parent[i] = -1;
    key[i] = INF;
    inMST[i] = false;
    heap->array[i] = createMinHeapNode(i, key[i]);
    heap->pos[i] = i;
  }
  key[0] = 0;
  decreaseKey(heap, 0, key[0]);
  heap->size = numVertices;
  while (!isEmpty(heap))
  {
    MinHeapNode *minNode = extractMin(heap);
    int u = minNode->vertex;
    inMST[u] = true;
    Edge *temp = graph->adjLists[u];
    while (temp != NULL)
    {
      int v = temp->dest;
      int weight = temp->weight;
      if (!inMST[v] && weight < key[v])
      {
        key[v] = weight;
        parent[v] = u;
        decreaseKey(heap, v, key[v]);
      }
      temp = temp->next;
    }
  }
  printMST(parent, graph->adjLists, numVertices);
}

int main()
{
  int numVertices;
  printf("Enter Number of Vertices: ");
  scanf("%d", &numVertices);
  Graph *graph = createGraph(numVertices);
  printf("Enter Graph:\n");
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      int weight;
      scanf("%d", &weight);
      if (weight != 0)
      {
        addEdge(graph, i, j, weight);
        addEdge(graph, j, i, weight);
      }
    }
  }
  primMST(graph);
  return 0;
}