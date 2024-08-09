#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int reads = n/4 + 1;
        while(reads--) {
            read4(buf);
            buf += 4;
        }
        return n;
    }
};