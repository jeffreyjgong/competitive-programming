#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;

        while(true) {
            while(root != NULL) {
                s.push(root);
                root = root->left;
            }

            root = s.top(); s.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};