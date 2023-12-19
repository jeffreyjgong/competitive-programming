#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>
#include<algorithm>

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

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first; // Sort in descending order of the first element
}

void solve(){
    int n;
    input(n);

    vector<int> a(n);
    vector<int> b(n);

    arrPut(a);
    arrPut(b);

    // (ev, index), done

    vector<pair<int, int>> ev;

    for(int i = 0; i<n; i++) {
        ev.push_back(make_pair(a[i] + b[i], i));
    }

    sort(ev.begin(), ev.end(), comparePairs);

    for(int i = 0; i<n; i++) {
        if (i % 2 == 0) {
            // alice
            a[ev[i].second]--;
            b[ev[i].second] = 0;
        } else {
            // bob
            b[ev[i].second]--;
            a[ev[i].second] = 0;
        }
    }

    int total_a = 0;
    int total_b = 0;
    for(int i = 0; i<n; i++) {
        total_a += a[i];
        total_b += b[i];
    }

    cout << total_a - total_b << endl;
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
