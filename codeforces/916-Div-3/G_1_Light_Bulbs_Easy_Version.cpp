#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>

using ll = long long;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n";
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << endl; print(args ...);}
#define ff first
#define D(x) cerr << #x " is " << (x) << endl
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define foreach(x, v) for (__typeof__ (v).begin() x=(v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define DFor(i, a, b) for (int i=(a); i>=b; --i)
#define ss second
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int ll

class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        for(int i = 0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unionSets(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

void dfs(int node, const unordered_map<int, unordered_set<int>>& adj, DisjointSet& ds, vector<bool>& visited) {
    visited[node - 1] = true;
    if (adj.find(node) != adj.end()) {
        for(int neighbor : adj.at(node)) {
            ds.unionSets(node - 1, neighbor - 1);
            if (!visited[neighbor-1]) {
                dfs(neighbor, adj, ds, visited);
            }
        }
    }
}

vector<vector<int>> findComponents(int n, const unordered_map<int, unordered_set<int>>& adj) {
    DisjointSet ds(n);

    vector<bool> visited(n, false);

    for(int i = 1; i<=n; i++) {
        if (!visited[i-1]) {
            dfs(i, adj, ds, visited);
        }
    }

    unordered_map<int, unordered_set<int>> components;
    for (int i = 0; i < n; ++i) {
        components[ds.find(i)].insert(i+1);
    }

    vector<vector<int>> result;
    for (auto& component : components) {
        vector<int> comp(component.second.begin(), component.second.end());
        result.push_back(comp);
    }

    return result;
}

void dfs2(int node, const unordered_map<int, unordered_set<int>>& adj, unordered_set<int>& visited) {
    visited.insert(node);
    if (adj.find(node) != adj.end()) {
        for(int neighbor : adj.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                dfs2(neighbor, adj, visited);
            }
        }
    }
}

vector<unordered_set<int>> findReachableNodes(int n, const unordered_map<int, unordered_set<int>>& adj) {
    vector<unordered_set<int>> reachable(n+1);

    for(int i = 1; i <= n; i++) {
        unordered_set<int> visited;
        dfs2(i, adj, visited);
        reachable[i] = visited;
    }
    return reachable;
}

void solve(){
    int n;
    input(n);

    vector<int> lb(2*n);

    arrPut(lb);

    vector<vector<int>> locs(n + 1);

    unordered_map<int, unordered_set<int>> adj;

    for(int i = 0; i<lb.size(); i++) {
        locs[lb[i]].push_back(i);
    }

    for(int i = 1; i<=n; i++) {
        for(int j = locs[i][0]+1; j<=locs[i][1]-1; j++) {
            adj[i].insert(lb[j]);
        }
    }

    auto components = findComponents(n, adj);

    auto reachableNodes = findReachableNodes(n, adj);

    vector<int> possibilities;

    for(auto component : components) {
        int compSize = component.size();
        int total = 0;
        for(int i = 0; i<compSize; i++) {
            if (reachableNodes[component[i]].size() == compSize) {
                total++;
            }
        }
        possibilities.push_back(total*2);
    }

    int minimumSize = possibilities[0];

    for(int i = 1; i<possibilities.size(); i++) {
        minimumSize = (possibilities[i] * minimumSize) % 998244353;
    }

    cout << components.size() << " " << (minimumSize % 998244353) << endl;
}

int32_t main() {
    setup();

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
