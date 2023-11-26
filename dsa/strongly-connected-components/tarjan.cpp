#include <bits/stdc++.h>

using namespace std;

#define NIL -1

class DirectedGraph {
    unordered_map<int, vector<int>> adj;

    void SCCUtil(int u, int disc[], int low[], stack<int>* st, bool stackMember[]);

public:
    void addEdge(int v, int w);

    void SCC();
};

void DirectedGraph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// A recursive function that finds and prints strongly
// connected components using DFS traversal u --> The vertex
// to be visited next disc[] --> Stores discovery times of
// visited vertices low[] -- >> earliest visited vertex (the
// vertex with minimum discovery time) that can be reached from
// subtree rooted with current vertex
// *st -- >> To store all the connected ancestors (could be
// part of SCC)
// stackMember[] --> bit/index array for faster check
// whether a node is in stack
void DirectedGraph::SCCUtil(int u, int disc[], int low[], stack<int>* st, bool stackMember[]) {
    static int time = 0;

}

int main() {

}