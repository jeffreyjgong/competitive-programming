#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // need to bfs obviously, but also need to keep track of which copies you have already made

        if (!node) return NULL;

        queue<Node*> q;
        q.push(node);

        // start a copy
        // real -> copy
        unordered_map<Node*, Node*> realToCopy;
        realToCopy[node] = new Node(node->val);

        while(!q.empty()) {
            Node* cur = q.front(); q.pop();

            for(Node* neighbor : cur->neighbors) {
                // if we've already traversed there then all we need to do is add this new edge
                // but if we haven't, then we need to add a new copy
                if (realToCopy.find(neighbor) == realToCopy.end()) {
                    realToCopy[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                realToCopy[cur]->neighbors.push_back(realToCopy[neighbor]);
            }
        }

        return realToCopy[node];
    }
};