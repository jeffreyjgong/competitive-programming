#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        const int m = s.size();
        int cur_g = 0;
        int total = 0;
        const int n = g.size();

        for(int i = 0; i<m; i++) {
            if (cur_g >= n) break;
            if (s[i] >= g[cur_g]) {
                cur_g++;
                total++;
            }
        }
        
        return total;
        
    }
};