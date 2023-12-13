#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;

        const int n = bills.size();

        for(int i = 0; i<n; i++) {
            int cur = bills[i];

            if (cur == 5) {
                fives++;
            } else if (cur == 10) {
                tens++;
                if (fives == 0) return false;
                fives--;
            } else {
                twenties++;
                if (tens == 0) {
                    if (fives < 3) return false;
                    fives-=3;
                } else {
                    // have a tens
                    tens--;
                    if (fives == 0) return false;
                    fives--;
                }
            }
        }

        return true;
    }
};