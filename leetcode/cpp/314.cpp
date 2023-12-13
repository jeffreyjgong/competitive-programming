#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        map<int, vector<int>> colToNodes;

        queue<pair<TreeNode*, int>> q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair<TreeNode*, int> cur = q.front(); q.pop();

            colToNodes[cur.second].push_back(cur.first->val);

            if (cur.first->left) {
                q.push(make_pair(cur.first->left, cur.second-1));
            }

            if (cur.first->right) {
                q.push(make_pair(cur.first->right, cur.second+1));
            }
        }

        for(auto const & x : colToNodes) {
            res.push_back(x.second);
        }

        return res;


    }
};