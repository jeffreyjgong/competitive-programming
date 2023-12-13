#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqs;

        const int n = arr.size();
        for(int i = 0; i<n; i++) {
            freqs[arr[i]]++;
        }

        auto compare = [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        };

        priority_queue<int> pq;

        for(auto const& x : freqs) {
            pq.push(x.second);
        }

        int half = n/2;
        int res = 0;

        while(half > 0) {
            half -= pq.top(); pq.pop();
            res++;
        }

        return res;
    }
};