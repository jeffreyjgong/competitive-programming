#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int bruh = -10e4-1;
        const int n = nums.size();

        int curNumber = nums[0];
        int curStreak = 1;
        int k = n;

        for(int i = 1; i<n; i++) {
            if (nums[i] == curNumber)
            {
                // streak continues
                curStreak++;
                if (curStreak > 2) {
                    // duplicate found
                    nums[i] = bruh;
                    k--;
                }
            }
            else
            {
                // new streak
                curNumber = nums[i];
                curStreak = 1;
            }
        }

        // two pointer approach
        int origTraverser = 0;

        for(int kFiller = 0; kFiller < k; kFiller++) {
            if (nums[origTraverser] != bruh) {
                // just fill
                nums[kFiller] = nums[origTraverser];
            } else {
                // need to skip to next
                while(nums[origTraverser] == bruh) {
                    origTraverser++;
                }
                nums[kFiller] = nums[origTraverser];
            }
            origTraverser++;
        }

        return k;
    }
};