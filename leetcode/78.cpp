#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> temp_list;

        backtrack(list, temp_list, nums, 0);
        return list;
    }

private:
    void backtrack(vector<vector<int>> &list, vector<int> &temp_list, vector<int> &nums, int start) {
        // choose no element
        vector<int> cur(temp_list.begin(), temp_list.end());
        list.push_back(cur);

        for(int i = start; i<nums.size(); i++) {
            temp_list.push_back(nums[i]);
            backtrack(list, temp_list, nums, i+1);
            temp_list.pop_back();
        }

    }
};