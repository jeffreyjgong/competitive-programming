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
typedef pair<int, int> pii;

bool is_valid(pii coord, int k) {
    if (coord.ff < 0 || coord.ff >= k || coord.ss < 0 || coord.ss >= k) {
        return false;
    }
    return true;
}

int32_t main() {
    setup();

    int k;
    input(k);

    // knight's attacking configuration can be represented as a 2x3 block
    // either 
    // x 0        0 x
    // 0 0   OR   0 0   OR the horizontal equivalent
    // 0 x        x 0
    // total number of distinct pairs (regardless of attacking)
    // first knight's choices: k^2
    // second knight's choices: k^2-1
    // account for double-counting: total = k^2 * (k^2-1) / 2

    For(i, 1, k+1) {
        int total = i*i*(i*i - 1) / 2;

        // vertical 3x2 blocks
        // top left corner can be in a (k-2)(k-1) square 
        // horizontal 2x3 blocks same by symmetry
        // remember each 2x3 block represents 2 knight configurations
        int conflicts = 4*max(i-2, (ll) 0)*max(i-1, (ll) 0);
        cout << total-conflicts << endl;
    }
    
    return 0;
}
