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

// cur_day is the day that you would do the second operation for the first time
int cur_score(const vector<int>& a, int n, int total_days, int cur_day) {
    int sum = 0;
    For(i, 1, n+1) {
        if (a[i] == i) {
            sum++;
        }
    }

    return sum + (total_days - cur_day)/2;
}

void solve() {
    int n, k, d;
    input(n,k,d);

    vector<int> a(n+1);
    For(i, 1, n+1) {
        int a_elem;
        input(a_elem);
        a[i] = a_elem;
    }

    vector<int> b(k+1);
    For(i, 1, k+1) {
        int b_elem;
        input(b_elem);
        b[i] = b_elem;
    }

    // EV of a move is always 0.5 because you can always turn 1st one and then immediately cash out

    // we need to go through and check for each day at the start, what the cash out value would be
    // however, d can be large so we need to somehow restrict what we need to check
    // well, we know that at most, we can get n score from the array. This is only worth doing if it takes
    // at most 2n-1 days, because the EV is already n/2 for each day. Thus, we need only check to min(d, 2n-1)

    int max_score = cur_score(a, n, d, 1);

    // i represents the day that you do the second operation

    for(int i = 2; i<=min(d, 2*n); i++) {
        // need to add day 1s
        // day 1 -> index 1, day 2 -> index 2, day 3 -> 3
        // 4 -> 1, 5 -> 2, 6-> 3
        int range_to_add = b[((i-1) % k) == 0 ? k : (i-1)%k];
        for(int j = 1; j<=range_to_add; j++) {
            a[j]++;
        }

        max_score = max(max_score, cur_score(a, n, d, i));
    }

    cout << max_score << endl;
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
