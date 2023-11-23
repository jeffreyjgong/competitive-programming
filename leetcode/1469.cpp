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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            // lonely condition
            if (cur->left != NULL) {
                if (cur->right == NULL) res.push_back(cur->left->val);
                q.push(cur->left);
            }
            
            if (cur->right != NULL) {
                if (cur->left == NULL) res.push_back(cur->right->val);
                q.push(cur->right);
            }
        }

        return res;

    }
};