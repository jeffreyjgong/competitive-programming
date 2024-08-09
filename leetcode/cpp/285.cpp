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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // first find p and keep track of its parent
        TreeNode* lastLeft = nullptr;
        while(root != p) {
            if (p->val < root->val) {
                // left child so keep track of parent
                lastLeft = root;
                root = root->left;
            } else {
                // right child so set parent to null
                root = root->right;
            }
        }

        TreeNode* lrs = getLowestOfRightSubchild(p);
        if (lrs) return lrs;
        return lastLeft;
    }

    TreeNode* getLowestOfRightSubchild(TreeNode* root) {
        root = root->right;
        while(root != nullptr) {
            root = root->left;
        }

        return root;
    }
};