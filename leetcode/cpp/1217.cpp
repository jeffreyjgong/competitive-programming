#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odds = 0;
        int evens = 0;

        for(int i = 0; i<position.size(); i++) {
            if (position[i] & 1) {
                odds++;
            } else {
                evens++;
            }
        }

        return min(odds, evens);
    }
};