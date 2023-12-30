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
    int n;
    input(n);

    vector<int> a(n);
    arrPut(a);

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    // do the 1 and 2 case
    vector<int> res(n);

    res[0] = a[0];
    res[1] = ((a[0] + a[1])/2)*2;

    vector<int> prefixSum(n);
    vector<pii> eo(n);
    if (a[0] % 2 == 0) {
        eo[0] = make_pair(1, 0);
    } else {
        eo[0] = make_pair(0, 1);
    }
    prefixSum[0] = a[0];
    For(i, 1, n) {
        prefixSum[i] = a[i] + prefixSum[i-1];
        if (a[i] % 2 == 0) {
            eo[i] = make_pair(eo[i-1].first+1, eo[i-1].second);
        } else {
            eo[i] = make_pair(eo[i-1].first, eo[i-1].second+1);
        }
    }

    For(i, 2, n) {
        int subtracts = eo[i].second / 3;
        if (eo[i].second % 3 == 1) {
            subtracts++;
        }

        res[i] = prefixSum[i] - subtracts;
    }

    foreach(x, res) {
        cout << *x << " ";
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
