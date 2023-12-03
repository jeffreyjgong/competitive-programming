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

    vector<int> a(n);
    arrPut(a);

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    int total_gcd = abs(a[1] - a[0]);
    int total_max = max(a[1], a[0]);

    unordered_set<int> freq;
    freq.insert(a[0]);
    freq.insert(a[1]);
    
    for(int i = 2; i<n; i++) {
        if (total_gcd != 1) total_gcd = gcd(total_gcd, abs(a[i] - a[i-1]));

        total_max = max(total_max, a[i]);
        freq.insert(a[i]);
    }

    int num_ops = 0;
    for(int j = 0; j<n; j++) {
        num_ops += ((total_max - a[j]) / total_gcd);
    }

    int i = total_max - total_gcd;
    int minimum = (long) -1000000000;
    int num = n;
    while(num--) {
        if (freq.find(i) == freq.end()) {
            cout << num_ops + (abs(total_max - i))/total_gcd << endl;
            return;
        }

        i -= total_gcd;
    }

    cout << num_ops + n << endl;
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
