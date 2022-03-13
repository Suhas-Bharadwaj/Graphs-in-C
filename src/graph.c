#include "graph.h"

Node* newNode(int data, int weight)
{
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node == NULL)
    {
        free(node);
        return NULL;
    }
    
    node->data = data;
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

    if (graph->V <= 0)
    {
        printf("\nHaving zero or negative nodes in a graph is not allowed.\n\n");
        free(graph);
        return NULL;
    }

    if (graph->V == 1)
    {
        printf("\nA graph data-structure is unnecessary for one node. Please use the newNode function.\n\n");
        free(graph);
        return(NULL);
    }

    graph->gMatrix = (Node***) calloc(sizeof(Node**), graph->V);

    if (graph->gMatrix == NULL)
    {
        free(graph->gMatrix);
        free(graph);
        return NULL;
    }
    
    for (int i = 0; i < graph->V; i++)
    {
        graph->gMatrix[i] = (Node**) calloc(sizeof(Node*), graph->V);

        if (graph->gMatrix[i] == NULL)
        {
            destroyGraph(graph);
            return NULL;
        }

        for (int j = 0; j < graph->V; j++)
        {
            graph->gMatrix[i][j] = (Node*) calloc(sizeof(Node), graph->V);

            if (graph->gMatrix[i][j] == NULL)
            {
                destroyGraph(graph);
                return NULL;
            }

            graph->gMatrix[i][j]->data = data;
            graph->gMatrix[i][j]->weight = weight;
        }
    }

    graph->adjMatrix = (int**) calloc(sizeof(int) * sizeof(graph->V), graph->V);

    if (graph->adjMatrix == NULL)
    {
        free(graph->adjMatrix);
        free(graph);
        return NULL;
    }

    for (int i = 0; i < graph->V; i++)
    {
        graph->adjMatrix[i] = (int*) calloc(sizeof(int) * sizeof(graph->V), graph->V);

        if (graph->adjMatrix[i] == NULL)
        {
            destroyGraph(graph);
            return NULL;
        }

        for (int j = 0; j < graph->V; j++)
        {
            graph->adjMatrix[i][j] = (int) calloc(sizeof(int) * sizeof(graph->V), graph->V);

            if (graph->adjMatrix[i][j] == 0)
            {
                destroyGraph(graph);
                return NULL;
            }
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
        if (graph->gMatrix[i] != NULL)
        {
            for (int j = 0; j < graph->V; j++)
            {
                if (graph->gMatrix[i][j] != NULL)
                {
                    free(graph->gMatrix[i][j]);
                }
            }

            free(graph->gMatrix[i]);
        }
    }

    free(graph->adjMatrix);
    free(graph->gMatrix);
    free(graph);
}

int hasEdge(Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0);
    assert(dest >= 0);

    if (graph->adjMatrix[src][dest] == 1)
    {
        return 1;
    }

    return -1;
}

int makeEdge(Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0);
    assert(dest >= 0);

    if (hasEdge(graph, src, dest) == 1)
    {
        return -1;
    }

    if (src == dest)
    {
        return -1;
    }

    return graph->adjMatrix[src][dest] = 1;
}

int destroyEdge(Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0);
    assert(dest >= 0);

    if (hasEdge(graph, src, dest) == 1)
    {
        return graph->adjMatrix[src][dest] = 0;
    }

    return -1;
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (hasEdge(graph, i, j) == 1)
            {
                printf("(%d)%d -> (%d)%d\n", graph->gMatrix[i][i]->data, i, graph->gMatrix[j][j]->data, j);
            }
        }
    }
}