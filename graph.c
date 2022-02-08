#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;
typedef struct Graph Graph;

Node* newNode(int data, int weight);
Graph* makeGraph(int V, int data, int weight);
void destroyGraph(Graph* graph);
int hasEdge(Graph* graph, int i, int j, int m, int n);
Graph* makeEdge(Graph* graph, int i, int j, int m, int n);
Graph* destroyEdge(Graph* graph, int i, int j, int m, int n);
void printGraph(Graph* graph);

struct Node
{
    int data;
    int weight;
    Node* dest;
};

struct Graph
{
    int V;
    Node*** adjMatrix;
};

Node* newNode(int data, int weight)
{
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node == NULL)
    {
        free(node);
        return NULL;
    }
    
    node->data = data;
    node->dest = NULL;
    return node;
}

Graph* makeGraph(int V, int data, int weight)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    
    if (graph == NULL)
    {
        free(graph);
        return NULL;
    }

    graph->V = V;

    graph->adjMatrix = (Node***) calloc(sizeof(Node**), graph->V);
    if (graph->adjMatrix == NULL)
    {
        free(graph->adjMatrix);
        free(graph);
        return NULL;
    }
    
    for (int i = 0; i < graph->V; i++)
    {
        graph->adjMatrix[i] = (Node**) calloc(sizeof(Node*), graph->V);

        if (graph->adjMatrix[i] == NULL)
        {
            destroyGraph(graph);
            return NULL;
        }

        for (int j = 0; j < graph->V; j++)
        {
            graph->adjMatrix[i][j] = (Node*) calloc(sizeof(Node), graph->V);

            if (graph->adjMatrix[i][j] == NULL)
            {
                destroyGraph(graph);
                return NULL;
            }

            graph->adjMatrix[i][j]->data = data;
            graph->adjMatrix[i][j]->weight = weight;
            graph->adjMatrix[i][j]->dest = NULL;
        }
    }
    return graph;
}

void destroyGraph(Graph* graph)
{
    if (graph == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        if (graph->adjMatrix[i] != NULL)
        {
            for (int j = 0; j < graph->V; j++)
            {
                if (graph->adjMatrix[i][j] != NULL)
                {
                    free(graph->adjMatrix[i][j]);
                }
            }

            free(graph->adjMatrix[i]);
        }
    }

    free(graph->adjMatrix);
    free(graph);
}

int hasEdge(Graph* graph, int i, int j, int m , int n)
{
    assert(graph != NULL);
    assert(m >= 0);
    assert(n >= 0);
    assert(i >= 0);
    assert(j >= 0);

    if (graph->adjMatrix[i][j]->dest == graph->adjMatrix[m][n])
    {
        return 1;
    }

    return -1;
}

Graph* makeEdge(Graph* graph, int i, int j, int m, int n)
{
    assert(graph != NULL);
    assert(m >= 0);
    assert(n >= 0);
    assert(i >= 0);
    assert(j >= 0);

    if (hasEdge(graph, i, j, m, n) == 1)
    {
        return NULL;
    }

    return graph->adjMatrix[i][j]->dest = graph->adjMatrix[m][n];
}

Graph* destroyEdge(Graph* graph, int i, int j, int m, int n)
{
    assert(graph != NULL);
    assert(m >= 0);
    assert(n >= 0);
    assert(i >= 0);
    assert(j >= 0);

    if (hasEdge(graph, i, j, m, n) == 1)
    {
        return graph->adjMatrix[i][j]->dest = NULL;
    }

    return NULL;
}

void printGraph(Graph* graph)
{  
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            for (int m = 0; m < graph->V; m++)
            {
                for (int n = 0; n < graph->V; n++)
                {
                    if (hasEdge(graph, i, j, m, n) == 1)
                    {
                        printf("%d(%d, %d)[%d] -> %d(%d, %d)[%d]\n", graph->adjMatrix[i][j]->data, i, j, graph->adjMatrix[i][j]->weight, graph->adjMatrix[m][n]->data, m, n, graph->adjMatrix[m][n]->weight);
                    }
                }
            }
        }
    }
}

void main()
{
    Graph* g = makeGraph(2, 0, 1);

    printGraph(g);
    destroyGraph(g);
}   