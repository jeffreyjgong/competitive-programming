#include<bits/stdc++.h>

using namespace std;

// im kinda the goat for this one

class Solution {
public:
    const vector<int> DIRS = {-1, 0, 1, 0, -1};

    void solve(vector<vector<char>>& board) {
        // start at edges
        
        // top 
        for(int c = 0; c<board[0].size(); c++) {
            if (board[0][c] == 'O') {
                turnTo(board, 'O', 'I', {0, c});
            }
        }

        // left
        for(int r = 1; r<board.size() - 1; r++) {
            if (board[r][0] == 'O') {
                turnTo(board, 'O', 'I', {r, 0});
            }
        }

        // right
        for(int r = 1; r<board.size() - 1; r++) {
            if (board[r][board[0].size() - 1] == 'O') {
                turnTo(board, 'O', 'I', {r, board[0].size() - 1});
            }
        }

        // bottom
        for(int c = 0; c<board[0].size(); c++) {
            if (board[board.size()-1][c] == 'O') {
                turnTo(board, 'O', 'I', {board.size()-1, c});
            }
        }

        // now all invalid ones are I's, we can safely turn all O's into X's and I's into O's

        for(int r = 0; r<board.size(); r++) {
            for(int c = 0; c<board[0].size(); c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'I') {
                    board[r][c] = 'O';
                }
            }
        }

    }

    void turnTo(vector<vector<char>>& board, char old, char _new, pair<int, int> startCoord) {
        if (old == _new) {
            return;
        }

        queue<pair<int, int>> q;
        q.push(startCoord);

        board[startCoord.first][startCoord.second] = _new;

        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(int i = 0; i<4; i++) {
                int new_r = cur.first + DIRS[i];
                int new_c = cur.second + DIRS[i+1];

                if (is_in(board, new_r, new_c)) {
                    if (board[new_r][new_c] == old) {
                        board[new_r][new_c] = _new;
                        q.emplace(new_r, new_c);
                    }
                }
            }
        }
    }

    bool is_in(vector<vector<char>>& board, int r, int c) {
        return (0 <= r) && (r < board.size()) && (c >= 0) && (c < board[0].size());
    }
};