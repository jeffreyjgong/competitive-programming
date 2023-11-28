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
    int maximum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        max_sum(root);
        return maximum;
    }

    int max_sum(TreeNode* root) {
        if (root == NULL) return 0;

        int l = max(max_sum(root->left), 0);
        int r = max(max_sum(root->right), 0);

        maximum = max(maximum, l + r + root->val);
        return max(l, r) + root->val;
    }
};