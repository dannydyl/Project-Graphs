#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "List.h"
#include "Edge.h"
#include <stack>

using namespace std;

void traverse(int v, vector<bool>& vis, const vector<List<Edge>>& g) {
    vis[v] = true;
    cout << "   " << v;

    for (auto& w : g[v]) {
        if (!vis[w.tv])
            traverse(w.tv, vis, g);
    }
}

void breadth_first_traversal(const vector<List<Edge>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front(); q.pop();
        cout << "Visited: " << current << endl;

        for (const Edge& edge : graph[current]) {
            if (!visited[edge.tv]) {
                visited[edge.tv] = true;
                q.push(edge.tv);
            }
        }
    }
}

void shortestpath(const vector<List<Edge>>& graph, int source) {
    int N = graph.size();
    vector<int> distance(N, INT_MAX);
    vector<int> parent(N, -1);
    vector<bool> processed(N, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[source] = 0;
    parent[source] = source;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue; // Ignore this node if it has been processed
        processed[u] = true; // Mark this node as processed

        for (const Edge& edge : graph[u]) {
            int v = edge.tv, weight = edge.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v}); // Only push if the distance was updated
            }
        }
    }

    cout << "Shortest Paths from Vertex " << source << ":" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Vertex " << i << ": Distance = " << distance[i];
        if (distance[i] == INT_MAX) {
            cout << " (unreachable)";
        } else {
            cout << ", Path: ";
            // Use stack to print path in correct order
            stack<int> path;
            for (int at = i; at != source; at = parent[at]) { // Loop until the source is reached
                path.push(at);
            }
            path.push(source); // Add the source at the end (or beginning when reversed)
            
            // Print the path from the source to the vertex
            while (!path.empty()) {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << " -> ";
            }
        }
        cout << endl;
    }

}


int main() {
    int nv, ne;
    cin >> nv >> ne;
    if (nv < 1 || nv > 10000 || ne < 0 || ne > 10000) {
        cerr << "Input values out of range." << endl;
        return 1;
    }

    vector<List<Edge>> graph(nv);
    for (int i = 0; i < ne; i++) {
        int cv1, cv2; double wt;
        cin >> cv1 >> cv2 >> wt;
        if (cv1 < 0 || cv1 >= nv || cv2 < 0 || cv2 >= nv || wt < 0 || wt > 10000.0) {
            cerr << "Edge values out of range." << endl;
            return 1;
        }
        graph[cv1].push_back(Edge(cv1, cv2, wt));
    }

    cout << endl << "Graph:" << endl;
    for (int i = 0; i < nv; i++) {
        cout << i << ": ";
        graph[i].printList();
    }

    vector<bool> visited(nv, false);
    cout << endl << "Depth First traversal:" << endl << "Order of vertices visited: ";
    for (int v = 0; v < nv; v++) {
        if (!visited[v])
            traverse(v, visited, graph);
    }
    cout << endl;

    breadth_first_traversal(graph, 0);
    cout << endl;

    shortestpath(graph, 0);

    return 0;
}
