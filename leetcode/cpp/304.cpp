#include<bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> topLeftSums;
    
    NumMatrix(vector<vector<int>>& matrix) {
        const int r = matrix.size();
        const int c = matrix[0].size();
        
        topLeftSums = vector<vector<int>>(r+1, vector<int>(c+1, 0));
        // dp fill in the topLeftSums starting from bottom right
        for(int row = r-1; row >= 0; row--) {
            for(int col = c-1; col>=0; col--) {
                topLeftSums[row][col] = matrix[row][col] + topLeftSums[row+1][col] + topLeftSums[row][col+1] - topLeftSums[row+1][col+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return topLeftSums[row1][col1] - topLeftSums[row1][col2+1] - topLeftSums[row2+1][col1] + topLeftSums[row2+1][col2+1];
    }
};