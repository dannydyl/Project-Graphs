Readme file for Project 4 By Dongyun Lee (112794190)

## Instructions
The project involves handling directed graphs using adjacency lists and performing various operations such as depth-first traversal, breadth-first traversal, and computing shortest paths. The primary requirements are as follows:
1. Modify the `main()` function to implement breadth-first traversal starting from each vertex.
2. Implement Dijkstra's algorithm to compute the shortest paths from each vertex to every other vertex, with a focus on computational efficiency.

## File Descriptions
- **Edge.h**: Defines the `Edge` class used to represent edges in the graph.
- **List.h**: Defines the `List` template class used for storing adjacency lists and implementing queues needed for BFS.
- **task1.cpp**: Contains the implementation for graph representation and DFS.
- **task2.cpp**: Contains the implementation for BFS and shortest path calculations.

## Input Format:
The program requires the input to be provided in a structured format:
The first line must contain two integers:
N: the number of vertices.
NE: the number of edges.
Each of the following NE lines should describe one edge with three values:
Vi: the starting vertex of the edge.
Vj: the ending vertex of the edge.
W: the weight of the edge (a floating-point number).