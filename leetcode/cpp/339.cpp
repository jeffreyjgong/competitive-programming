#include<bits/stdc++.h>

using namespace std;

class NestedInteger {
    public:
        NestedInteger();

        NestedInteger(int value);

        bool isInteger() const;

        int getInteger() const;

        void setInteger();

        void add(const NestedInteger &ni);

        const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int depth = 1;
        int res = 0;
        queue<NestedInteger> q;

        for(auto &ni : nestedList) {
            q.push(ni);
        }

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                NestedInteger cur = q.front();
                q.pop();

                if (cur.isInteger()) {
                    res += cur.getInteger() * depth;
                } else {
                    vector<NestedInteger> adj = cur.getList();
                    for(auto & ni : adj) {
                        q.push(ni);
                    }
                }
            }

            depth++;
        }

        return res;
    }
};