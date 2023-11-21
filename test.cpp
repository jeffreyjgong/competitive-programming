#include<bits/stdc++.h>

using namespace std;

int main() {
    map<int, string> mymap;

    if (mymap.begin() == mymap.end()) {
        cout << "yay same" << endl;
    }

    mymap[1] = 2;

    auto it = mymap.lower_bound(4);
    
    
    if (it == mymap.begin()) {
        cout << "begin" << endl;
    } else if (it == mymap.end()) {
        cout << "end" << endl;
    }
}