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

int findClosestValue(const vector<int>& arr, int k) {
    auto iter_geq = lower_bound(
        arr.begin(),
        arr.end(),
        k
    );

    if (iter_geq == arr.begin()) {
        return arr[0];
    }

    int a = *(iter_geq -1);
    int b = *(iter_geq);

    if (abs(k - a) < abs(k - b)) {
        return a;
    }

    return b;
}

void solve(){
    int n, k;
    input(n, k);

    vector<int> a(n);
    arrPut(a);
    
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());

    int min_diff = LLONG_MAX;

    for(int i = 1; i<a.size(); i++) {
        min_diff = min(min_diff, abs(a[i] - a[i-1]));
    }

    if (k == 1) {
        cout << min(min_diff, a[0]) << endl;
        return;
    }

    int min_new_diff_diff = LLONG_MAX;
    
    for(int i = 0; i<n-1; i++) {
        for(int j = i+1; j<n; j++) {
            int x = abs(a[i] - a[j]);
            int min_new_diff = abs(x - findClosestValue(a, x));
            if (min_new_diff == 0) {
                cout << 0 << endl;
                return;
            }

            min_new_diff_diff = min(min_new_diff_diff, min_new_diff);
        }
    }

    cout << min(min_new_diff_diff, min(min_diff, a[0])) << endl
    
    return;
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
