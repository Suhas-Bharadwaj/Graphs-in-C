#include "graph.h"

void main()
{
    int numNodes, data, weight;

    numNodes = 5;
    data = 0;
    weight = 1;
    
    /* Creating the graph */
    Graph* g = makeGraph(numNodes, data, weight);

    /* Makes edges between all nodes in the graph */
    for (int i = 0; i < g->V; i++)
    {
        for (int j = 0; j < g->V; j++)
        {
            makeEdge(g, i, j);
        }
    }
    
    /* Changing the data and weight of node 0 */
    g->gMatrix[0][0]->data = 1;
    g->gMatrix[0][0]->weight = 3;
    
    /* Destroys an edge between the specified indeces */
    destroyEdge(g, 0, 1);

    printGraph(g);
    destroyGraph(g);
}   
