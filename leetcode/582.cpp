#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        vector<int> res;

        for(int i = 0; i<pid.size(); i++) {
            children[ppid[i]].push_back(pid[i]);
        }

        queue<int> q;
        q.push(kill);

        while(!q.empty()) {
            int cur = q.front();

            q.pop();

            res.push_back(cur);
            vector<int> &adjs = children[cur];
            for(auto i : adjs) {
                q.push(i);
            }
        }

        return res;
    }
};