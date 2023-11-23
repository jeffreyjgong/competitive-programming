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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        return helper(root->left, LONG_MIN, root->val) && helper(root->right, root->val, LONG_MAX);
    }

    bool helper(TreeNode* root, long min, long max) {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;

        return helper(root->left, min, root->val) && helper(root->right, root->val, max);

    }
};