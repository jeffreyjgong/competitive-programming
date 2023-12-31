#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>

using ull = unsigned long long;
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
#define uint ull
#define odd(x) (x & 1)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;

inline int32_t factorial(int n) {
    int32_t fac = 1;
    DFor(i, n, 2) {
        fac*=i;
    }
    return fac;
}

int32_t main() {
    setup();

    string s;
    input(s);

    sort(all(s));

    int cur_streak = 1;
    vector<int> streaks;
    For(i, 1, s.size()) {
        if (s[i] != s[i-1]) {
            streaks.push_back(cur_streak);
            cur_streak = 1;
        } else {
            // equal
            cur_streak++;
        }
    }
    streaks.push_back(cur_streak);
    
    int total_conflicts = 1;
    foreach(x, streaks) {
        total_conflicts *= factorial(*x);
    }

    int total = factorial(s.size()) / total_conflicts;

    unordered_set<string> unique;

    cout << total << endl;

    do {
        if (unique.insert(s).ss) {
            total--;
            cout << s << endl;
        }
    } while (next_permutation(s.begin(), s.end()) && total);
    return 0;
}
