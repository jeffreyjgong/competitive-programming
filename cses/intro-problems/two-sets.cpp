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

int32_t main() {
    setup();

    int n;
    input(n);

    // sum is n*(n+1)/2
    // need that to be even
    // that means n*(n+1) == 0 mod 4
    // casework
    // obviously n = 0 (mod 4) works
    // n = 1 (mod 4) doesn't work, because 1*2 == 2 mod 4
    // n = 2 (mod 4) doesn't work because 2*3 == 2 mod 4
    // n = 3 (mod 4) works because 3*4 == 0 mod 4

    if (n%4 != 3 && n % 4 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        if (n%4 == 0) {
            // then we use groups of 4
            // (1, 4 | 2, 3)

            cout << n/2 << endl;
            for(int i = 0; i<=n-4; i+=4) {
                cout << i + 1 << " " << i + 4 << " ";
            }
            cout << endl;
            cout << n/2 << endl;
            for(int i = 0; i<=n-4; i+=4) {
                cout << i+2 << " " << i+3 << " ";
            }
            cout << endl;
        } else {
            // then we use groups of 4
            // then groups of 3 (1, 2 | 3)
            cout << (n/2) + 1 << endl;
            cout << 1 << " " << 2 << " ";
            for(int i = 3; i<=n-4; i+=4) {
                cout << i + 1 << " " << i + 4 << " ";
            }
            cout << endl;
            cout << n/2 << endl;
            cout << 3 << " ";
            for(int i = 3; i<=n-4; i+=4) {
                cout << i+2 << " " << i+3 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
