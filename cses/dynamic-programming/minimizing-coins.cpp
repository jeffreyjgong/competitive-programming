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
#define mp make_pair
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;

int32_t main() {
    setup();

    int n, s;
    input(n, s);

    vector<int> coins(n);
    arrPut(coins);

    int dp[s+1];
    For(i, 0, s+1) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;


    // dp[i] is the minimum number of coins needed to get to weight i

    for(int weight = 1; weight <= s; weight++) {
        for(int coin = 0; coin < n; coin++) {
            if (weight - coins[coin] >= 0) {
                dp[weight] = min(dp[weight], dp[weight - coins[coin]] + 1);
            }
        }
    }

    cout << (dp[s] == INT_MAX ? -1 : dp[s]) << endl;
    return 0;
}
