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
typedef pair<int, int> pii;

void solve(){
    int n, k;
    input(n, k);

    vector<int> a(n);
    arrPut(a);

    if (n==1) {
        cout << 0 << endl;
        return;
    }
    int sum = 0;

    bool less_k = false;
    bool greater_k = false;
    bool all_equal = true;

    for(int i = 0; i<a.size(); i++) {
        if (a[i] < k) {
            less_k = true;
        }

        if (a[i] > k) {
            greater_k = true;
        }

        if (i > 0) {
            if (a[i] != a[i-1]) {
                all_equal = false;
            }
        }

        sum += a[i];
    }

    if (less_k && greater_k) {
        cout << -1 << endl;
        return;
    }

    // bruh
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
