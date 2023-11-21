#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // [low, high] inclusive
        int MOD = 1000000007;
        int dp[high+1];
        for(int i = 0; i<high+1; i++) {
            dp[i] = 0;
        }

        int lowest = min(zero, one);
        dp[zero] += 1;
        dp[one] += 1;

        long sum = 0;
        for(int i = lowest; i<=high; i++) {
            dp[i] += dp[max(i - zero, 0)] + dp[max(i - one, 0)];
            dp[i] %= MOD;

            if (i >= low) {
                sum += (dp[i] % MOD);
            }
        }
        
        return (int) (sum % MOD);
    }
};