#include "graph.h"
#include <string.h>

Graph* squareGraph(int n, int data, int weight)
{
    Graph* sq_g = makeGraph(n*n, data, weight);

    for (int i = 0; i < sq_g->V; i++)
    {
        for (int j = 0; j < n; j++)
        {
            makeEdge(sq_g, i, j);
        }
    }

    return sq_g;
}

void main()
{
    int numNodes, data, weight;

    numNodes = 2;
    data = 0;
    weight = 1;

    Graph* g = squareGraph(numNodes, data, weight);
    

    printGraph(g);
    destroyGraph(g);
}   