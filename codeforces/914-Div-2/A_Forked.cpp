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

bool check_queen(int xq, int yq, int a, int b, int xn, int yn) {
    // possibility 1
    if (abs(xq - xn) == a && abs(yq - yn) == b) {
        return true;
    }

    if (abs(xq - xn) == b && abs(yq - yn) == a) {
        return true;
    }

    return false;
}

void solve(){
    int a, b;
    input(a,b);

    int xk, yk;
    input(xk, yk);

    int xq, yq;
    input(xq, yq);

    // check 8

    int res = 0;
    if (a != b) {
        if (check_queen(xq, yq, a, b, xk + a, yk + b)) res++;

        if (check_queen(xq, yq, a, b, xk + b, yk + a)) res++;

        if (check_queen(xq, yq, a, b, xk + a, yk - b)) res++;

        if (check_queen(xq, yq, a, b, xk + b, yk - a)) res++;

        if (check_queen(xq, yq, a, b, xk - a, yk + b)) res++;

        if (check_queen(xq, yq, a, b, xk - a, yk - b)) res++;

        if (check_queen(xq, yq, a, b, xk - b, yk + a)) res++;

        if (check_queen(xq, yq, a, b, xk - b, yk - a)) res++;
    } else {
        if (check_queen(xq, yq, a, b, xk + a, yk + b)) res++;

        if (check_queen(xq, yq, a, b, xk + a, yk - b)) res++;

        if (check_queen(xq, yq, a, b, xk - a, yk + b)) res++;

        if (check_queen(xq, yq, a, b, xk - a, yk - b)) res++;
    }
    

    cout << res << endl;
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
