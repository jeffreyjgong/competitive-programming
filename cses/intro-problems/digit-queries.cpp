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

inline int pow10(int x) {
    ll res = 1;
    For(i, 0, x) {
        res *= 10;
    }
    return res;
}

void solve(){
    int k;
    input(k);

    // 9x1 digit 9 = 9x1
    // 90x2 9x20 digit 189 = 9x21
    // 900x3 9x300 digit 2889 = 9x321
    // 9000x4 9x4000
    
    // first make it 0-indexed
    k--;
    if (k < 9) {
        cout << k+1 << endl;
        return;
    }

    int cur_digit = 1;

    while(k - 9*cur_digit*pow10(cur_digit-1) >= 0) {
        k -= 9*cur_digit*pow10(cur_digit-1);
        cur_digit++;
    }

    int number = pow10(cur_digit-1) + k/cur_digit;
    string number_string = to_string(number);
    cout << number_string[k%cur_digit] << endl;

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
