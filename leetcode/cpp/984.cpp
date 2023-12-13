#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s;

        while(a && b) {
            if (a > b) {
                s += "aab";
                a--;
            } else if (b > a) {
                s += "bba";
                b--;
            } else {
                s += "ab";
            }

            a--; b--;
        }

        if (a > 0) s += string(a, 'a');
        if (b > 0) s += string(b, 'b');

        return s;
        
    }
};