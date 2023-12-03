#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
    int n, P, l, t;
    input(n, P, l, t);

    // day of work value
    int num_avail_tasks = ceil(n/7.0);

    // maximize lesson + 2 task day
    int day_3_value = l + 2*t;
    int points_left = P;
    int num_avail_3_day = 0;
    if (num_avail_tasks >= 2) {
        num_avail_3_day = num_avail_tasks/2;
        int num_3_needed = ceil((ld)P/(day_3_value));
        if (num_avail_3_day >= num_3_needed) {
            cout << n - num_3_needed << endl;
            return;
        } else {
            // num_avail < num_3_needed
            points_left = points_left - num_avail_3_day * day_3_value;
        }
    }

    // maximize lesson + 1 day
    if (num_avail_tasks % 2 == 1) {
        int num_2_needed = ceil((ld) points_left / (l + t));
        if (num_2_needed == 1) {
            cout << n - num_avail_3_day - 1 << endl;
            return;
        } else {
            points_left = points_left - (l+t);
            cout << n - num_avail_3_day - 1 - (int) ceil((ld) points_left / l) << endl;
            return;
        }
    }

    cout << n - num_avail_3_day - (int) ceil((ld) points_left / l) << endl;
    
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
