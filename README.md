# Graphs in C
This is a full implementation of graphs in C.

#(Deprecated in favour of my data structures repository.)

# How to use
The make graph function takes in the pointer to graph, the weight each node has and the number of nodes in the graph. Destroy graph frees up the memory that was allocated to the graph. The print graph function takes in the graph as the argument and prints data and the nodes if an edge exists between the said nodes.

The make edge function takes in the pointer to graph, source node and destination node and the destroy edge function takes in the same arguments.

The make edge and destroy edge functions change the values in the adjacency matrix to either a 1 or a 0 depeneding on the state of the edge between the nodes.

The data in a node can be changed using the set data and get data functions.

# How it works
There is an array of structures which holds all the nodes in the graph and an adjacency matrix which is an array of integers store the state of the edge between the nodes. The array of structures (referred to as gMatrix) store pointers to struct node. This is mirrored in the adjacency matrix but it stores integers instead. This allows us to check the adjacency matrix for the state of the edge while working with the nodes in the gMatrix and since the indeces are all synchronized, the functions can be used without much alteration to the arguments.

# Known issues and nuances
1. Cast from integer of different size warning is issued at line 133.
2. Making a graph that replicates a mesh is not trivial.
3. Passing the indeces of nodes that aren't initialized in the graph results in a segmentation fault.

# How to compile
The main file has to be compiled along with the graph.c and graph.h files in order for it to work. It can be done as
                    ```gcc main.c graph.h graph.c```.
If you wish to rename the output file at compilation, following the gcc command with ```-o {filename}``` will do so.
