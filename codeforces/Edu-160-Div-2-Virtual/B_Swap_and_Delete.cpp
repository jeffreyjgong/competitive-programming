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
    string s;
    input(s);

    const int n = s.size();

    if (n == 1) {
        println(1);
        return;
    }

    int zeros = 0;
    int ones = 0;

    For(i, 0, s.size()) {
        if (s[i] == '0') zeros++;
        else ones++;
    }

    if (zeros == ones) {
        println(0);
        return;
    }

    if (zeros == 0) {
        println(ones);
        return;
    } else if (ones == 0) {
        println(zeros);
        return;
    }

    // iterate and see if we can build t
    int i = 0;
    while(true) {
        if (s[i] == '0') ones--;
        else if (s[i] == '1') zeros--;

        if (ones < 0 || zeros < 0) break;

        i++;
    }

    println(n-i);
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
