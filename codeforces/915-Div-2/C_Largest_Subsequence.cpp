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

    string s;
    input(s);

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<pair<int, int>> a(n);

    for(int i = 0; i<n; i++) {
        a[i] = make_pair(int(s[i]), i);
    }
    
    vector<pair<int, int>> breakpoints;

    int curMax = int(s[n-1]);

    breakpoints.push_back(a[n-1]);
    
    for(int i = n-2; i>=0; i--) {
        if (a[i].first >= curMax) {
            curMax = a[i].first;
            breakpoints.push_back(a[i]);
        }
    }

    int num_duplicates = 0;

    for(int i = breakpoints.size()-2; i>=0; i--) {
        if (breakpoints[i].first == breakpoints[i+1].first) {
            num_duplicates++;
        } else {
            break;
        }
    }

    for(int i = 0; i<breakpoints.size(); i++) {
        a[breakpoints[breakpoints.size()-i-1].second] = breakpoints[i];
    }

    for(int i = 1; i<n; i++) {
        if (a[i].first < a[i-1].first) {
            cout << -1 << endl;
            return;
        }
    }

    cout << breakpoints.size() - 1 - num_duplicates << endl;
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
