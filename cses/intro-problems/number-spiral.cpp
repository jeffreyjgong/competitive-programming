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
typedef pair<int, int> pii;

void solve(){
    int row, col;
    input(row, col);

    int square = max(row, col);

    int r, c;

    if (odd(square)) {
        r = 1;
        c = square;
    } else {
        r = square;
        c = 1;
    }

    cout << square*square - (abs(row - r) + abs(col - c)) << endl;
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
