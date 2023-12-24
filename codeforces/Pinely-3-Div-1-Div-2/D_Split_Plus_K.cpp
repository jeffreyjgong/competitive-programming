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
    int n, k;
    input(n, k);

    vector<int> a(n);

    bool all_neg = true;
    bool all_pos = true;
    bool all_zero = true;
    bool all_same = true;
    For(i, 0, n) {
        int a_elem;
        input(a_elem);
        a[i] = a_elem - k;

        if (a[i] != a[0]) {
            all_same = false;
        }
        
        if (a[i] < 0) {
            all_pos = false;
            all_zero = false;
        } else if (a[i] == 0) {
            all_neg = false;
            all_pos = false;
        } else {
            all_neg = false;
            all_zero = false;
        }
    }

    // already all same (all_zero is subset of all_same but for readability)
    if (all_same || all_zero) {
        cout << 0 << endl;
        return;
    }

    // mixed
    if (!all_pos && !all_neg) {
        cout << -1 << endl;
    } else {
        // get gcd of whole thing
        int g = a[0];
        For(i, 1, n) {
            g = __gcd(g, a[i]);
        }

        // c is num of times to apply to operation
        // a_i + ck = m*(1 + c) because c operations create 1+c pieces
        // solve for c
        // c = (a_i - m)/(m-k) 
        // m - k is gcd and m = gcd+k
        // thus c = (a_i - gcd - k) / (gcd) = (a_i - k)/gcd - 1
        // and a_i is already -= k, so just (a[i]/g) - 1
        
        int num_ops = 0;
        For(i, 0, n) {
            num_ops += (a[i]/g) - 1;
        }

        cout << num_ops << endl;
    }
    
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
