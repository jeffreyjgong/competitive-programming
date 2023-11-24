#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto s : stones) {
            pq.push(s);
        }

        while(!pq.empty() && pq.size() != 1) {
            int high1 = pq.top(); pq.pop();
            int high2 = pq.top(); pq.pop();

            if (high2 != high1) {
                pq.emplace(abs(high2-high1));
            }
        }

        if (pq.size() == 1) {
            return pq.top();
        } else {
            return 0;
        }
    }
};