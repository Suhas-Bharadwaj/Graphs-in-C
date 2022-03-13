#include "graph.h"

void main()
{
    int numNodes, data, weight;

    numNodes = 5;
    data = 0;
    weight = 1;

    Graph* g = makeGraph(numNodes, data, weight);

    for (int i = 0; i < g->V; i++)
    {
        for (int j = 0; j < g->V; j++)
        {
            makeEdge(g, i, j);
        }
    }

    printGraph(g);
    destroyGraph(g);
}   