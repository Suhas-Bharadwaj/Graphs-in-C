#include "graph.h"

/* Allocates memory to make a node */
Node* newNode(int data, int weight)
{
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node == NULL)
    {
        free(node);
        return NULL;
    }

    //node->data_test.i_data = data;
    node->data = data;
    return node;
}

/* Sets data to diagonal elements in gMatrix */
int setData(Graph* graph, int node, int data) 
{
    return graph->gMatrix[node][node]->data = data;
}

/* Returns data from diagonal elements in gMatrix */
int getData(Graph* graph, int node) 
{
    return graph->gMatrix[node][node]->data;
}

/* Sets weight to diagonal elements in gMatrix */
int setWeight(Graph* graph, int node, int weight) 
{
    return graph->gMatrix[node][node]->weight = weight;
}

/* Returns weight from diagonal elements in gMatrix */
int getWeight(Graph* graph, int node) 
{
    return graph->gMatrix[node][node]->weight;
}

/* Allocates memory to graph and adjacency matrix */
Graph* makeGraph(int V, int data, int weight) 
{
    /* Allocating memory to graph */
    Graph* graph = (Graph*) malloc(sizeof(Graph)); 
    
    if (graph == NULL)
    {
        free(graph);
        return NULL;
    }

    /* Setting number of vertices to V */
    graph->V = V; 

    if (graph->V <= 0)
    {
        perror("\nHaving zero or negative nodes in a graph is not allowed.\n\n");
        free(graph);
        return NULL;
    }

    if (graph->V == 1)
    {
        perror("\nA graph data-structure is unnecessary for one node. Please use the newNode function.\n\n");
        free(graph);
        return(NULL);
    }

    /* Allocating memory to triple pointer to make a 2D array and store pointers to node in that array */
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
            /* Allocating memory only to diagonal elements to store data and access nodes */
            if (i == j)
            {
                graph->gMatrix[i][j] = (Node*) calloc(sizeof(Node), graph->V);

                if (graph->gMatrix[i][j] == NULL)
                {
                    destroyGraph(graph);
                    return NULL;
                }

                setData(graph, i, data);
                setWeight(graph, i, weight);
            }
        }
    }

    /* Allocating memory to adjacency matrix which is a 2D array */
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

/* Function to free all allocated memory to graph and adjacency matrix */
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

/* Function that returns true if an edge exists between two nodes */
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

/* Making an edge between two nodes by changing the value in adjacency matrix to 1 */
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

/* Removing an edge between two nodes by changing the value in the adjacency matrix to 0 */
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

/* Utility function to print graph if an edge exists between two nodes */
void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (hasEdge(graph, i, j) == 1)
            {
                printf("(%d)%d -> (%d)%d\n", getData(graph, i), i, getData(graph, j), j);
            }
        }
    }
}