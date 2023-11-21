#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v(
            matrix[0].size(),
            vector<int>(matrix.size())
        );

        for(int r = 0; r<matrix.size(); r++) {
            for(int c = 0; c<matrix[0].size(); c++) {
                v[c][r] = matrix[r][c];
            }
        }

        return v;
    }
};