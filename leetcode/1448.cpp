#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int res = 0;
        helper(root, INT_MIN, res);

        return res;
    }

    void helper(TreeNode * root, int cur_max, int &res) {
        if (root == NULL) {
            return;
        }

        if (root->val >= cur_max) {
            res++;
        }

        helper(root->left, max(root->val, cur_max), res);
        helper(root->right, max(root->val, cur_max), res);

    }
};