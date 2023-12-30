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

    int start = 1;

    For(i, 0, n) {
        if (a[i] == 1 || a[i] == 7 || a[i] == 17 || a[i] == 119 || a[i] == 289 || a[i] == 2023) {
            start *= a[i];
            if (start > 2023) {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if (2023 % start != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int needed = 2023/start;

    cout << needed << " ";
    For(i, 0, k-1) {
        cout << 1 << " ";
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
