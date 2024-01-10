#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        tuple<int, int, int> flag_col_45_135 = {0, 0, 0};
        solve(res, nQueens, flag_col_45_135, 0, n);
        return res;
    }
private:
    inline bool bitmaskGood(int index, int bitmask) {
        return (bitmask & (1 << index)) == 0;
    }

    inline void setBitmask(int index, int& bitmask) {
        bitmask = bitmask | (1 << index);
    }
    
    void solve(vector<vector<string>>& res, vector<string>& nQueens, tuple<int, int, int>& flag_col_45_135, int row, int n) {
        if (row == n) {
            res.push_back(nQueens);
        }

        // 

        for(int col = 0; col<n; col++) {
            if ()
        }
    }
};