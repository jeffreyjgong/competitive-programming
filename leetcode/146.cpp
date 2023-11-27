#include<bits/stdc++.h>

using namespace std;

class LRUCache {
    unordered_map<int, pair<list<int>::iterator, int>> table;
    list<int> dll;
    int cap;
    int total_elements;

    void moveToFirst(int key) {
        dll.erase(table[key].first);
        dll.push_front(key);
        table[key].first = dll.begin();
    }
public:

    LRUCache(int capacity) {
        this->cap = capacity;
        this->total_elements = 0;
    }
    
    int get(int key) {
        if (table.find(key) == table.end()) return -1;

        moveToFirst(key);
        return table[key].second;
    }
    
    void put(int key, int value) {
        if (table.find(key) != table.end()) {
            // already exists
            table[key].second = value;
            moveToFirst(key);
        } else {
            // doesn't already exist
            dll.push_front(key);
            table[key] = make_pair(dll.begin(), value);
            total_elements++;
        }

        if (total_elements > cap) {
            table.erase(dll.back());
            dll.pop_back();
            total_elements--;
        }
    }
};