#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        // power of 4 means 2^(2n) for some n
        // this just means that binary representation has one 1 at an odd location
         return (n > 0) && ((n & (n-1)) == 0) && ((n & 0xAAAAAAAA) == 0);
    }
};