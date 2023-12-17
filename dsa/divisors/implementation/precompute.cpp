#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

// you can do this before the solve while loop so all test cases have access to it

int main(void) {
    const int N = 1e5;

    // contains all the divisors of numbers 1 through N
    vector<vector<int>> divisors(N+1);

    // O(NlogN)

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            divisors[j].emplace_back(i);
        }
    }

    // test
    for(int i = 1; i<20; i++) {
        cout << i << ": ";
        for(auto j : divisors[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}