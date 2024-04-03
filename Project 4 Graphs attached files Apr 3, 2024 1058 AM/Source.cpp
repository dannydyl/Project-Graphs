#include <iostream>
using namespace std;
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for sqrt()
#include "List.h"
#include "Edge.h"

void traverse(int v, vector<bool>& vis, const vector<List<Edge>>& g) {
	vis[v] = true;
	
	//cout << "Visited vertex : " << v << endl;
	cout << "   " << v;

	for (auto& w : g[v]) {
		if (!vis[w.tv])
			traverse(w.tv, vis, g);
	}
}

int main() {
	
	int nv = 0; // number of vertices
	int ne = 0; // number of edges
	cin >> nv >> ne; // input; assume no error in input.
	cout  << "Input:  nv = " << nv << " , ne =  " << ne  << endl;

    if( (nv<0) || (nv>10000) || (ne<0) || (ne>10000) ) {
		cerr << "Input values out of range." << endl;
		exit(1);
	}

	vector<List<Edge>> g2(nv); //graph
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
		g2[cv1].push_back(nsq);
	}
	cout << endl << "Graph " << endl;
	for (int i = 0; i < nv; i++) {
		cout << i << " : ";
		g2[i].printList();
	//	cout << endl;
	}
	vector<bool> visited(nv, false);
	cout <<endl<< "Depth First traversal " << endl<< "Order of vertices visited : " ;
	for (int v = 0; v < nv; v++) {
		if (!visited[v])
			traverse(v, visited,g2);
	}
	cout << endl;

	for (int i = 0; i < nv; i++) {
	//	cout << i << " : Cleared ";
		g2[i].clear();
		cout << endl;
	}

	return 0;
}
