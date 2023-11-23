#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;

        vector<int> temp_path;

        helper(graph, res, temp_path, 0);

        return res;
    }

    void helper(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& temp_path, int cur) {
        temp_path.push_back(cur);

        if (cur == graph.size() - 1) {
            res.push_back(temp_path);
            temp_path.pop_back();
            return;
        }

        for(auto adj : graph[cur]) {
            helper(graph, res, temp_path, adj);
        }
        temp_path.pop_back();
    }
};