#include <iostream>
using namespace std;
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for sqrt()
#include "List.h"
#include "Edge.h"

void traverse(int v, vector<bool>& vis, const vector<List<Edge>>& g) {
	vis[v] = true;  // vertices are visited and marked true
	
	//cout << "Visited vertex : " << v << endl;
	cout << "   " << v;

	for (auto& w : g[v]) {
		if (!vis[w.tv])
			traverse(w.tv, vis, g);
	}
}

void breadth_first_traversal(const vector<List<Edge>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    vector<int> q;  // Using vector as a queue

    int frontIndex = 0;  // This will track the "front" of the queue

    // Start by marking the starting vertex as visited and adding it to the queue
    visited[start] = true;
    q.push_back(start); // add the starting vertex into the queue

    // While there are still elements in the queue
    while (frontIndex < q.size()) {
        int current = q[frontIndex];  // Get the current vertex from the front of the queue
        frontIndex++;  // "Remove" the element from the front of the queue

        // Visit the vertex (in this case, just print it)
        cout << "Visited: " << current << endl;

        // Add all unvisited adjacent vertices to the back of the queue
        for (const Edge& edge : graph[current]) {
            if (!visited[edge.tv]) {
                visited[edge.tv] = true;
                q.push_back(edge.tv);
            }
        }
    }
}


int main() {
	
	int nv = 0; // number of vertices
	int ne = 0; // number of edges
	cin >> nv >> ne; // input; assume no error in input.
	cout  << "Input:  nv = " << nv << " , ne =  " << ne  << endl;

    if( (nv<0) || (nv>10000) || (ne<0) || (ne>10000) ) {    // 0 < nv < 10000, 0 < ne < 10000 is the range
		cerr << "Input values out of range." << endl;
		exit(1);
	}

	vector<List<Edge>> Vertx(nv); //graph   // number of nv is the number of lists
    // each list is a vertex and contains the edges from that vertex

	int cv1 = 0, cv2 = 0; // Edge from current vertex cv1 to cv2
	double wt = 0.0; // weight

	for(int ne1=0; ne1<ne; ne1++)
	 {
		cin >> cv1 >> cv2 >> wt; // input; assume no error in input.
		if ((cv1 < 0) || (cv1 > nv) || (cv2 < 0) || (cv2 > nv) || (wt<0) || (wt >10000.0)) {
			cerr << "Input values out of range." << endl;
			exit(1);
		}
		Edge nsq(cv1, cv2, wt);
		Vertx[cv1].push_back(nsq);
	}
	cout << endl << "Graph " << endl;
	for (int i = 0; i < nv; i++) {
		cout << i << " : ";
		Vertx[i].printList();
	//	cout << endl;
	}
	vector<bool> visited(nv, false);    // initially all vertices are unvisited so false

	cout <<endl<< "Depth First traversal " << endl<< "Order of vertices visited : " ;
	for (int v = 0; v < nv; v++) {
		if (!visited[v])
			traverse(v, visited,Vertx);
	}
	cout << endl;

    breadth_first_traversal(Vertx, 0);



	for (int i = 0; i < nv; i++) {
	//	cout << i << " : Cleared ";
		Vertx[i].clear();
		cout << endl;
	}

	return 0;
}
