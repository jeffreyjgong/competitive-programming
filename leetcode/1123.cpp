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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) return NULL;
        
        int left_depth = get_depth(root->left);
        int right_depth = get_depth(root->right);
        if (left_depth == right_depth) {
            return root;
        } else {
            if (right_depth > left_depth) {
                return lcaDeepestLeaves(root->right);
            } else {
                return lcaDeepestLeaves(root->left);
            }
        }
    }

    int get_depth(TreeNode* root) {
        if (root == NULL) return 0;

        return 1 + max(get_depth(root->left), get_depth(root->right));
    }
};