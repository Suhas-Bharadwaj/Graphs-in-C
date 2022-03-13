# Graphs-in-C
<H1>This is a full implementation of graphs in C where each node can store integer values for data and have weights associated with them. </H1>
The make edge and destroy edge functions take in the pointer to graph, source node and destination node for the edge as arguments.
The print graph function only prints the data and the node if an edge exists between the two.

There is an 2D adjacency matrix of bool that coexists with a 2D array of structures that constiutes the graph. Making and destroying edges is done by changing the values in the adjacency matrix.

By default, this program will make a 2x2 graph with 0 as the data for the nodes which all have unit weight.

If the indices of unavailable nodes are passed, a segmentation fault occurs.
