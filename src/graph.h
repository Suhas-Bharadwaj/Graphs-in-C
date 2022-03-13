#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;

typedef struct Graph Graph;

struct Node
{
    int data;
    int weight;
};

struct Graph
{
    int V;
    Node*** gMatrix;
    int** adjMatrix;
};

Node* newNode(int data, int weight);

Graph* makeGraph(int V, int data, int weight);

void destroyGraph(Graph* graph);

int hasEdge(Graph* graph, int src, int dest);

int makeEdge(Graph* graph, int src, int dest);

int destroyEdge(Graph* graph, int src, int dest);

void printGraph(Graph* graph);

#endif