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
    int n, k;
    input(n, k);

    vector<int> a(n);
    vector<int> b(n);

    arrPut(a);
    arrPut(b);

    vector<int> runningMaxB(n);

    runningMaxB[0] = b[0];

    for(int i = 1; i<runningMaxB.size(); i++) {
        runningMaxB[i] = max(b[i], runningMaxB[i-1]);
    }

    vector<int> prefixSumA(n);

    prefixSumA[0] = a[0];

    for(int i = 1; i < prefixSumA.size(); i++) {
        prefixSumA[i] = prefixSumA[i-1] + a[i];
    }

    int maxScore = INT_MIN;

    for(int i = 0; i<min(n, k); i++) {
        // calculate stopping at i-th index
        int total_score = prefixSumA[i] + (k-(i+1))*(runningMaxB[i]);
        maxScore = max(maxScore, total_score);
    }

    cout << maxScore << endl;
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
