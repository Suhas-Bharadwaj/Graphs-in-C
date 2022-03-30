#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;
typedef struct Graph Graph;
typedef union dataType dataType;

union dataType
{
    int i_data;
    float f_data;
    char c_data;
};


struct Node
{   
    //dataType data_test;
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

int setData(Graph* graph, int node, int data);

int getData(Graph* graph, int node);

int setWeight(Graph* graph, int node, int weight);

int getWeight(Graph* graph, int node);

#endif