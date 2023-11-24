#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        const int n = people.size();

        int lightest = 0;
        int heaviest = n-1;

        int boats = 0;

        while(lightest < heaviest) {
            if (people[lightest] + people[heaviest] <= limit) {
                lightest++;
                heaviest--;
            } else {
                heaviest--;
            }

            boats++;
        }
        
        return lightest == heaviest ? boats+1 : boats;
    }
};