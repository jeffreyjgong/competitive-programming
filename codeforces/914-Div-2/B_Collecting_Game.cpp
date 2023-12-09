#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>

using ll = long long;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n";
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << endl; print(args ...);}
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

void solve(){
    int n;
    input(n);

    vector<pair<int, int>> a;

    for(int i = 0; i<n; i++) {
        int num;
        cin >> num;
        a.push_back(make_pair(num, i));
    }

    sort(a.begin(), a.end());

    vector<int> prefix_sum(n);

    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += a[i].first;
        prefix_sum[i] = sum;
    }

    vector<int> dp(n);
    dp[n-1] = n-1;

    for(int i = n-2; i>=0; i--) {
        if (prefix_sum[i] >= a[i+1].first) {
            dp[i] = dp[i+1];
        } else {
            dp[i] = max(i, (ll) 0);
        }
    }

    for(int i = 0; i<n; i++) {
        prefix_sum[a[i].second] = dp[i];
    }

    for(int i = 0; i<n; i++) {
        cout << prefix_sum[i] << " ";
    }

    cout << endl;

}

int32_t main() {
    setup();

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
