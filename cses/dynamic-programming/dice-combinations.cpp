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

int32_t main() {
    setup();

    const int mod = 1e9 + 7;

    int n;
    input(n);
    
    vector<int> dp(n+1, 0);
    For(i, 1, 7) {
        dp[i] = 1;
    }

    For(i, 2, n+1) {
        dp[i] += dp[i-1];
        dp[i] = dp[i] % mod;
        dp[i] += dp[max((ll) 0, i-2)];
        dp[i] = dp[i] % mod;
        dp[i] += dp[max((ll) 0, i-3)];
        dp[i] = dp[i] % mod;
        dp[i] += dp[max((ll) 0, i-4)];
        dp[i] = dp[i] % mod;
        dp[i] += dp[max((ll) 0, i-5)];
        dp[i] = dp[i] % mod;
        dp[i] += dp[max((ll) 0, i-6)];
        dp[i] = dp[i] % mod;
    }

    cout << dp[n] % mod << endl;

    return 0;
}
