# Graphs-in-C
This is a full implementation of graphs in C where each node can store integer values for data and have weights associated with them. 
The make edge and destroy edge functions take the indices of the node and either create a pointer to the said node or set that pointer to NULL.
The print graph function only prints the data and indices of the node along with the weight if an edge exists between the two.

By default, this program will make a 2x2 graph with 0 as the data for the nodes which all have unit weight.

If the indices of unavailable nodes are passed, a segmentation fault occurs.
A warning for incompatible pointer type is issued at compilation for the make edge and destroy edge functions which I was unable to fix.
