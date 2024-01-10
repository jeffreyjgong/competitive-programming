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
    inline bool bitmaskClear(int index, int bitmask) {
        return (bitmask & (1 << index)) == 0;
    }

    inline void setBitmask(int index, int& bitmask) {
        bitmask = bitmask | (1 << index);
    }

    inline void unsetBitmask(int index, int& bitmask) {
        bitmask = bitmask & ~(1 << index);
    }

    inline int which45(int row, int col, int n) {
        // if (row == col) {
        //     return n;
        // } else if (row < col) {
        //     int index = col-row;
        //     return n+index;
        // } else {
        //     int index = row - col;
        //     return n-index;
        // }
        return n - (row - col);
    }

    inline int which135(int row, int col) {
        return row+col;
    }
    
    void solve(vector<vector<string>>& res, vector<string>& nQueens, tuple<int, int, int>& flag_col_45_135, int row, int n) {
        if (row == n) {
            res.push_back(nQueens);
        }

        for(int col = 0; col<n; col++) {
            if (
                bitmaskClear(col, get<0>(flag_col_45_135)) && 
                bitmaskClear(which45(row, col, n), get<1>(flag_col_45_135)) && 
                bitmaskClear(which135(row, col), get<2>(flag_col_45_135))
            ) {
                setBitmask(col, get<0>(flag_col_45_135)); setBitmask(which45(row, col, n), get<1>(flag_col_45_135)); setBitmask(which135(row, col), get<2>(flag_col_45_135));
                nQueens[row][col] = 'Q';
                solve(res, nQueens, flag_col_45_135, row+1, n);
                nQueens[row][col] = '.';
                unsetBitmask(col, get<0>(flag_col_45_135)); unsetBitmask(which45(row, col, n), get<1>(flag_col_45_135)); unsetBitmask(which135(row, col), get<2>(flag_col_45_135));
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<string>> res = s.solveNQueens(8);
    cout << res.size() << " solutions." << endl;

    for(auto &x : res) {
        for(auto &y: x) {
            cout << y << endl;
        }
        cout << endl;
    }
}