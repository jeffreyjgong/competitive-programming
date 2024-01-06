#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n";
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void println(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void println(T outVar, S... args) {cout << outVar << endl; print(args ...);}
#define ff first
#define D(x) cerr << #x " is " << (x) << endl
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define foreach(x, v) for (__typeof__ (v).begin() x=(v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define DFor(i, a, b) for (int i=(a); i>=b; --i)
#define ss second
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int ll
#define uint ull
#define odd(x) (x & 1)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;

int get_difference(int sum, const vector<int>& p, int bitmask, int n) {
    int orig = sum;
    for(int i = 0; i<n; i++) {
        int bit_index = 1 << i;
        sum -= ((bitmask & bit_index) != 0) ? p[i] : 0;
    }

    return abs(sum - (orig - sum));
}

int32_t main() {
    setup();

    // pretty sure this is a partition NP hard problem
    // thus need to recognize that this is necessarily done by brute force
    // the hint is that n<=20

    int n;
    input(n);

    int sum = 0;
    vector<int> p(n);
    For(i, 0, n) {
        input(p[i]);
        sum += p[i];
    }

    // now need to test all groups of size 0 to n/2
    // basically iterate and find all binary numbers that have less than or equal to n/2 1's

    // max number we need to go to is number that starts with n/2 1's
    int max_number = 0;
    for(int i = 0; i<n/2; i++) {
        max_number += (1 << (n - 1 - i));
    }

    int min_diff = LLONG_MAX;
    int tested = 0;

    for(uint i = 0; i<=max_number; i++) {
        if (__builtin_popcountll(i) <= n/2) {
            tested++;
            int cur_diff = get_difference(sum, p, i, n);
            min_diff = min(min_diff, cur_diff);
        }
    }
    
    cout << min_diff << endl;
    return 0;
}
