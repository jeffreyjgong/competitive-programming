#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> temp_list;

        backtrack(list, temp_list, nums);

        return list;
    }

private:
    void backtrack(vector<vector<int>> &list, vector<int> &temp_list, vector<int> &nums) {
        if (temp_list.size() == nums.size()) {
            list.push_back(temp_list);
        } else {
            for(int i = 0; i<nums.size(); i++) {
                if (find(temp_list.begin(), temp_list.end(), nums[i]) != temp_list.end()) {
                    continue;
                } else {
                    temp_list.push_back(nums[i]);
                    backtrack(list, temp_list, nums);
                    temp_list.pop_back();
                }
            }
        }
    }
};