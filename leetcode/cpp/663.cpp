#include<bits/stdc++.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    unordered_map<int, int> sums;

    bool checkEqualTree(TreeNode* root) {
        int rootSum = getSum(root);
        sums[rootSum]--;

        if (rootSum & 1) return false;

        auto finder = sums.find(rootSum/2);
        if (finder != sums.end())
        {
            return (*finder).second > 0;
        }
        return false;
    }

    int getSum(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int n = root->val + getSum(root->left) + getSum(root->right);

        sums[n]++;
        return n;
    }
};