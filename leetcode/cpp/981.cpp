#include<bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    unordered_map<string, map<int, string, greater<int>>> time_map;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto &stored_map = time_map[key];

        stored_map[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto &stored_map = time_map[key];

        auto it = stored_map.lower_bound(timestamp);
        if (it == stored_map.end()) {
            // returns the first key that is less than or equal to timestamp (because greater in map above)
            return "";
        }

        return it->second;
    }
};
