#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct Graph Graph;
Node* newNode(int data, int weight);
Graph* makeGraph(int V, int data, int weight);
void gDestroy(Graph* graph);
void gPrint(Graph* graph);
Node* gMakeEdge(Graph* graph, int x, int y, int i, int j);
Node* gDestroyEdge(Graph* graph, int i, int j);
bool gHasEdge(Graph* graph, int x, int y, int i, int j);

struct Graph
{
    int V;
    struct Node
    {
        int data;
        int weight;
        Node* dest;
    }Node;
    Node*** adjMatrix;
};

Node* newNode(int data, int weight)
{
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL)
    {
        return NULL;
    }
    node->data = data;
    node->weight = weight;
    node->dest = NULL;
    return node;
}

Graph* makeGraph(int V, int data, int weight)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    if (graph == NULL)
    {
        return NULL;
    }
    graph->V = V;

    graph->adjMatrix = calloc(sizeof(Node**), graph->V);
    if (graph->adjMatrix == NULL)
    {
        free(graph);
        return NULL;
    }
    for (int i = 0; i < graph->V; i++)
    {
        graph->adjMatrix[i] = calloc(sizeof(Node*), graph->V);
        if (graph->adjMatrix[i] == NULL)
        {
            gDestroy(graph);
            return NULL;
        }
        for (int j = 0; j < graph->V; j++)
        {
            graph->adjMatrix[i][j] = calloc(sizeof(Node), graph->V);
            if (graph->adjMatrix[i][j] == NULL)
            {
                gDestroy(graph);
                return NULL;
            }
            graph->adjMatrix[i][j]->data = data;
            graph->adjMatrix[i][j]->weight = weight;
            graph->adjMatrix[i][j]->dest = NULL;
        }
    }

    return graph;
}

void gDestroy(Graph* graph)
{
    if (graph->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        if (graph->adjMatrix[i] != NULL)
        {
            free(graph->adjMatrix[i]);
        }
    }
    free(graph->adjMatrix);
    free(graph);
}

void gPrint(Graph* graph)
{
    int n = 0; int m = 0;
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (graph->adjMatrix[i][j])
            {
                if (graph->adjMatrix[i][j]->dest != NULL)
                {
                    printf("%d]%d -> %d(%d)\n", n, graph->adjMatrix[i][j]->data, graph->adjMatrix[i][j]->dest->data ,graph->adjMatrix[i][j]->weight);
                }
                printf("%d]%d -> %d(%d)\n", n,graph->adjMatrix[i][j]->data, graph->adjMatrix[i][j]->data ,graph->adjMatrix[i][j]->weight);
                n++;
            }
        }
    }
}

bool gHasEdge(Graph* graph, int x, int y, int i, int j)
{
    assert(graph != NULL);
    assert(x <= graph->V);
    assert(y <= graph->V);
    assert(i <= graph->V);
    assert(j <= graph->V);
    if (graph->adjMatrix[x][y]->dest == graph->adjMatrix[i][j])
    {
        return true;
    }
}

Node* gMakeEdge(Graph* graph, int x, int y, int i, int j)
{
    assert(graph != NULL);
    assert(x <= graph->V);
    assert(y <= graph->V);
    assert(i <= graph->V);
    assert(j <= graph->V);
    if (!gHasEdge(graph, x, y, i, j))
    {
        if (i == j)
        {
            return NULL;
        }
        graph->adjMatrix[x][y]->dest = graph->adjMatrix[i][j];
    }
}

Node* gDestroyEdge(Graph* graph, int i, int j)
{
    return graph->adjMatrix[i][j]->dest = NULL;
}

int main()
{
    Graph* g = makeGraph(2, 0, 1);
    g->adjMatrix[1][1]->data=8;
    gMakeEdge(g, 0, 0, 1, 1);
    gDestroyEdge(g, 0, 0);
    gPrint(g);
    gDestroy(g);
    return 0;
}