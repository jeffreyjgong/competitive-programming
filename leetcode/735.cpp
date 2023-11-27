#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> right_moving;
        vector<int> res;

        for(auto asteroid : asteroids) {
            if (asteroid > 0) {
                right_moving.push_back(asteroid);
            } else {
                // negative asteroid
                bool destroyed_eachother = false;
                while(right_moving.size() > 0) {
                    int cur_asteroid = right_moving.back();
                    int new_asteroid = abs(asteroid);
                    if (new_asteroid > cur_asteroid) {
                        right_moving.pop_back();
                    } else if (new_asteroid == cur_asteroid) {
                        right_moving.pop_back();
                        destroyed_eachother = true;
                        break;
                    } else {
                        break;
                    }
                }

                if (right_moving.size() == 0 && !destroyed_eachother) {
                    res.push_back(asteroid);
                }
            }
        }

        res.insert(res.end(), right_moving.begin(), right_moving.end());
        return res;
    }
};