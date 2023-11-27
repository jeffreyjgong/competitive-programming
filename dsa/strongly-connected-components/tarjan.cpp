#include <bits/stdc++.h>

using namespace std;

#define NIL -1

class DirectedGraph {
    int V;
    list<int>* adj;

    void SCCUtil(int u, int disc[], int low[], stack<int>* st, bool stackMember[], vector<vector<int>>& sccs);

public:
    DirectedGraph(int V);

    void addEdge(int v, int w);

    vector<vector<int>> SCC();
};

DirectedGraph::DirectedGraph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void DirectedGraph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// A recursive function that finds and prints strongly
// connected components using DFS traversal u --> The vertex
// to be visited next disc[] --> Stores discovery times of
// visited vertices low[] -- >> stores for every vertex u,
// the earliest discovered vertex to which u or any of the vertices 
// in the dfs subtree rooted at v has a back edge to
// *st -- >> To store all the connected ancestors (could be
// part of SCC)
// stackMember[] --> bit/index array for faster check
// whether a node is in stack
void DirectedGraph::SCCUtil(int u, int disc[], int low[], stack<int>* st, bool stackMember[], vector<vector<int>> &sccs) {
    static int time = 0;
    // node is head when disc[u] == low[u]
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    // Go through all adjacent vertices
    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is the current adjacent vertex of u

        // if v is not visited yet then recur for it
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember, sccs);

            // check if the subtree rooted with 'v' has a 
            // connection to one of the ancestors of 'u'

            // Case 1 (Tree Edge)
            // if node v is not visited already
            // then after the dfs of v is complete 
            // we update low[u] with min(low[u], low[v])

            low[u] = min(low[u], low[v]);
        }

        // Case 2 (Back Edge) 
        // Update low[u] only if 'v' is still in stack
        // meaning it is a back edge.
        else if (stackMember[v] == true) {
            low[u] = min(low[u], disc[v]);
        }
    }

    vector<int> scc;
    int w = 0;
    // head node found, pop the stack and print SCC
    if (low[u] == disc[u]) {
        while(st->top() != u) {
            w = (int) st->top();
            scc.push_back(w);
            stackMember[w] = false;
            st->pop();
        }

        w = (int) st->top();
        scc.push_back(w);
        stackMember[w] = false;
        st->pop();
        sccs.push_back(scc);
    }
}

// the function that does the DFS traversal
vector<vector<int>> DirectedGraph::SCC() {
    int* disc = new int[V];
    int* low = new int[V];
    bool* stackMember = new bool[V];
    vector<vector<int>> sccs;
    stack<int>* st = new stack<int>();

    // Initialize disc and low, and stackMember
    for(int i = 0; i<V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }

    // Call the recursive helper function to find SCCs

    for(int i = 0; i<V; i++) {
        if (disc[i] == NIL) {
            SCCUtil(i, disc, low, st, stackMember, sccs);
        }
    }

    return sccs;
}

int main() {
    DirectedGraph g1(5);
    
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "SCC g1" << endl;
    vector<vector<int>> sccs = g1.SCC();

    cout << "[";
    for(size_t j = 0; j<sccs.size(); j++) {
        vector<int>& scc = sccs[j];
        cout << "[";
        for(size_t i = 0; i<scc.size(); i++) {
            cout << scc[i];
            if (i != (size_t) (scc.size() - 1)) {
                cout << ",";
            }
        }
        cout << "]";
        if (j != sccs.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << endl;

    DirectedGraph g4(11);
    g4.addEdge(0, 1);
    g4.addEdge(0, 3);
    g4.addEdge(1, 2);
    g4.addEdge(1, 4);
    g4.addEdge(2, 0);
    g4.addEdge(2, 6);
    g4.addEdge(3, 2);
    g4.addEdge(4, 5);
    g4.addEdge(4, 6);
    g4.addEdge(5, 6);
    g4.addEdge(5, 7);
    g4.addEdge(5, 8);
    g4.addEdge(5, 9);
    g4.addEdge(6, 4);
    g4.addEdge(7, 9);
    g4.addEdge(8, 9);
    g4.addEdge(9, 8);
    
    cout << "SCC g4" << endl;
    sccs = g4.SCC();

    cout << "[";
    for(size_t j = 0; j<sccs.size(); j++) {
        vector<int>& scc = sccs[j];
        cout << "[";
        for(size_t i = 0; i<scc.size(); i++) {
            cout << scc[i];
            if (i != scc.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (j != (size_t) (sccs.size() - 1)) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << endl;
}