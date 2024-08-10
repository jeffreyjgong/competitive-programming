#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;

        int min = INT_MIN;

        s.push(preorder[0]);

        for(int i = 1; i<preorder.size(); i++) {
            if (preorder[i] < s.top()) {
                if (preorder[i] < min) {
                    return false;
                }
                s.push(preorder[i]);
            } else {
                while(!s.empty() && preorder[i] > s.top()) {
                    min = s.top(); s.pop();
                }
                s.push(preorder[i]);
            }
        }

        return true;
    }
};