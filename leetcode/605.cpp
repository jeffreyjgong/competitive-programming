#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        const int m = flowerbed.size();
        int flowers_placed = 0;

        for(int i = 0; i<m; i++) {
            if (flowerbed[i] == 0) {
                if (flowerbed[max(0, i - 1)] == 0 && flowerbed[min(m - 1, i+1)] == 0) {
                    flowers_placed++;
                    flowerbed[i] = 1;
                    if (flowers_placed == n) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};