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

    vector<int> l(n);
    arrPut(l);
    set<int> r;
    for(int i = 0; i<n; i++) {
        int r_elem;
        input(r_elem);
        r.insert(r_elem);
    }
    vector<int> c(n);

    arrPut(c);

    sort(c.rbegin(), c.rend());

    // L
    sort(l.begin(), l.end());

    vector<int> intervals;

    for(auto it = l.rbegin(); it != l.rend(); ++it) {
        auto greater = r.upper_bound(*it);
        if (greater != r.end()) {
            intervals.push_back(*greater - *it);
            r.erase(greater);
        }
    }

    sort(intervals.begin(), intervals.end());

    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += c[i] * intervals[i];
    }
    
    cout << sum << endl;


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
