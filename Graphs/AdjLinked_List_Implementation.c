
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
	int address;
	struct AdjListNode *next;
};
typedef struct AdjListNode NODE;

struct AdjList
{
	NODE *head;
};
typedef struct AdjList LIST;

struct Graph
{
	int V;            // Number of Vertex in graph
	LIST *array;
};
typedef struct Graph GRAPH;

NODE *newAdjListNode(int address)
{
	NODE *newNode =(NODE*) malloc(sizeof(NODE));
	newNode->address = address;
	newNode->next = NULL;
	return newNode;
}


GRAPH* createGraph(int V)
{
	GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
	graph->V = V;
  graph->array = (LIST*) malloc(V * sizeof(LIST));
  int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;
  return graph;
}


void addEdge(GRAPH* graph, int src, int address)
{
  NODE* newNode = newAdjListNode(address);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src);
	newNode->next = graph->array[address].head;
	graph->array[address].head = newNode;
}

void printGraph(GRAPH* graph)
{
	int v;
	for (v = 0; v < graph->V; v++)
	{
		NODE* temp = graph->array[v].head;
		printf("\n\t Adjacency list of vertex %d\n\t head ", v);
		while (temp)
		{
			printf("-> %d", temp->address);
			temp = temp->next;
		}
		printf("\n");
	}
}

void main()
{

	int V = 5;
	GRAPH* graph = createGraph(V);
  int a;
  while(a!=0) {
    printf("\n\n");
    printf("Enter 1 -> Add Edge\n");
    printf("Enter 2 -> Print Graph\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    if(a==0) {
      printf("-------------------------Thank You----------------------------\n");
      return;
    }
    switch(a) {
      case 1 :
      {
        int u, v;
        printf("Enter u, v\n");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
        break;
      }
      case 2 :
      {
        printGraph(graph);
        break;
      }
      default :
      {
        printf("Wrong Value Detacted\n");
        break;
      }
      return;
    }
  }
}
