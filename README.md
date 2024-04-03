# ESE 344: Graphs - Adjacency Lists, Depth-First and Breadth-First Traversal, and Shortest Paths

## Overview

This repository is dedicated to Project 4 from the course ESE 344: Software Techniques for Engineers at Stony Brook University, instructed by Prof. Murali Subbarao. The project delves into the concepts of graphs, specifically focusing on adjacency lists, depth-first traversal, breadth-first traversal, and finding the shortest paths in a directed graph.

## Project Description

The project entails the implementation of several graph-related algorithms in C++, without the use of Standard Template Library (STL) classes (except for `vector`). The main tasks include:

1. Developing a breadth-first traversal function starting from each vertex (0 to N-1).
2. Implementing a shortest paths algorithm to find and print the shortest paths from a source vertex to all other vertices.

## Key Concepts

- **Adjacency Lists**: Representing a directed graph where each vertex stores a list of which vertices it is connected to and the weights of the edges.
- **Depth-First Traversal (DFT)**: A graph traversal method that explores as far as possible along each branch before backtracking.
- **Breadth-First Traversal (BFT)**: A graph traversal method that explores all the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
- **Shortest Paths**: Finding the minimum distance or minimum weight path from a starting vertex to other vertices in the graph.

## Implementation Details

- **Breadth-First Traversal**: Implemented using a queue data structure, specifically using the provided `List` class for managing the traversal order.
- **Shortest Paths Algorithm**: Implemented to calculate the minimum distances from a source vertex to all other vertices, not using an adjacency matrix but the provided adjacency list implementation for efficiency.
- **Efficiency Improvements**: Enhanced the shortest paths algorithm for computational efficiency, optimizing the selection process for the next vertex to add to the set of vertices with known shortest paths.

## Repository Structure

- `src`: Contains the source code for the project including the main application and additional modules for graph processing.
- `include`: Contains all header files defining the classes and functions used in the project.
- `data`: Sample input files representing graphs in the specified input format.
- `docs`: Additional documentation, including project specifications and reference materials.

## Building and Running

1. Compile the source code using a C++ compiler, ensuring all header and source files are correctly included.
2. Run the executable, providing an input file when prompted or redirecting an input file through the command line.
3. Review the output, which includes the traversal orders and shortest path details.


