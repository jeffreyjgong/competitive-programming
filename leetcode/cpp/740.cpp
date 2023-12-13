#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int buckets[10001] = {0};

        int lowest = INT_MAX;
        int highest = INT_MIN;

        for(auto num : nums) {
            lowest = min(lowest, num);
            highest = max(highest, num);
            buckets[num]+=num;
        }

        int dp[highest-lowest+1];
        if (highest-lowest+1 == 1) {
            return buckets[lowest];
        }
        
        for(int i = 0; i<highest-lowest+1; i++) {
            dp[i] = 0;
        }
        dp[0] = buckets[lowest];
        dp[1] = max(buckets[lowest], buckets[lowest+1]);

        for(int i = lowest+2; i<=highest; i++) {
            dp[i - lowest] = max(dp[i-lowest-2] + buckets[i], dp[i-lowest-1]);
        }

        return dp[highest-lowest];
    }
};