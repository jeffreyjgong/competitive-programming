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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        queue<TreeNode*> pQ;
        queue<TreeNode*> qQ;

        pQ.push(p);
        qQ.push(q);

        while(!pQ.empty() || !qQ.empty())
        {
            if (pQ.size() != qQ.size()) return false;

            TreeNode* curP = pQ.front(); pQ.pop();
            TreeNode* curQ = qQ.front(); qQ.pop();

            if (!curP && !curQ)
            {
                continue;
            }
            else if (curP->val != curQ->val)
            {
                return false;
            }

            // left

            if ((curP->left == nullptr) != (curQ->left == nullptr))
            {
                return false;
            }

            if ((curP->right == nullptr) != (curQ->right == nullptr))
            {
                return false;
            }

            pQ.push(curP->left);
            qQ.push(curQ->left);
            pQ.push(curP->right);
            qQ.push(curQ->right);

            // right
        }

        return true;
    }
};