#include<bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<string> findRelativeRanks(vector<int>& score) {
//         const int n = score.size();
//         vector<string> ranks(n, "");
        
//         vector<pair<int, int>> score_with_indices;

//         for(int i = 0; i<n; i++)
//         {
//             score_with_indices.emplace_back(score[i], i);
//         }
        
//         sort(score_with_indices.begin(), score_with_indices.end(), greater<>());

//         for(int i = 0; i<n; i++)
//         {
//             const auto& score_with_index = score_with_indices[i];
//             ranks[score_with_index.second] = calc_rank(i);
//         }

//         return ranks;
//     }

//     inline string calc_rank(int n) {
//         if (n == 0)
//         {
//             return "Gold Medal";
//         } else if (n == 1)
//         {
//             return "Silver Medal";
//         } else if (n == 2)
//         {
//             return "Bronze Medal";
//         } else {
//             return to_string(n+1);
//         }
//     }
// };

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        auto max = max_element(score.begin(), score.end());
        if (max == score.end())
        {
            return vector<string>{};
        }

        const int n = score.size();
        const int m = *max;

        vector<int> scoreToIndex(m+1, -1);

        for(int i = 0; i<n; i++) {
            scoreToIndex[score[i]] = i;
        }

        const vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        vector<string> ranks(n);
        int curRank = 0;
        for(int i = m; i>=0; i--) {
            // meaning it exists in the original array
            if (scoreToIndex[i] != -1) {
                ranks[scoreToIndex[i]] = (curRank < 3) ? medals[curRank] : to_string(curRank+1);
                curRank++;
            }
        }

        return ranks;
    }
};