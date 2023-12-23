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

int rightmostSetBit(int n) {
    if (n == 0) return 0;

    // Using bitwise AND of n and -n
    int rightmostBit = n & (-n);

    // Finding the position of the rightmost set bit
    int position = 1; // Position starts from 1
    while ((rightmostBit & 1) == 0) {
        rightmostBit = rightmostBit >> 1;
        position++;
    }
    return position;
}

void solve(){
    int n;
    input(n);

    vector<int> a(n);
    
    arrPut(a);

    int start = 2;
    
    while(start <= 1000000000000000000) {
        unordered_set<int> seen;
        
        for(int i = 0; i<n; i++) {
            seen.insert(a[i] % start);
            if (seen.size() > 2) break;
        }

        if (seen.size() == 2) {
            cout << start << endl;
            return;
        }
        start = start * 2;
    }

    cout << -1 << endl;

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
