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
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) return 0;
        int total_sum = 0;

        // even
        if (root->val % 2 == 0) {
            if (root->left != NULL) {
                total_sum += root->left->left ? root->left->left->val : 0;
                total_sum += root->left->right ? root->left->right->val : 0;
            }

            if (root->right != NULL) {
                total_sum += root->right->left ? root->right->left->val : 0;
                total_sum += root->right->right ? root->right->right->val : 0;
            }
        }

        return total_sum + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    }
};