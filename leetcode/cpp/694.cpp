#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};
    string dir_names[4] = {"W", "N", "E", "S"};

    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> unique;
        for(int r = 0; r<grid.size(); r++) {
            for(int c = 0; c<grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    string s;
                    s.append("R");
                    sink(grid, r, c, s);
                    unique.insert(s);
                }
            }
        }

        return unique.size();
    }

    void sink(vector<vector<int>>& grid, int r, int c, string& offsets) {

        grid[r][c] = 0;
        for(int i = 0; i<4; i++) {
            int new_r = r + dirs[i];
            int new_c = c + dirs[i+1];

            if (valid(grid, new_r, new_c) && grid[new_r][new_c] == 1) {
                offsets.append(dir_names[i]);
                sink(grid, new_r, new_c, offsets);
            }
        }
        // need to separate dfs layers
        offsets.append(",");
    }

    bool valid(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return false;
        } 
        return true;
    }
};