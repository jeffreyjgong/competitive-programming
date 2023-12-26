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
    int n;
    input(n);

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i<n; i++) {
        arrPut(matrix[i]);
    }

    if (n == 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }

    vector<int> a(n);
    For(i, 0, n) {
        int a_elem = (i == 0) ? matrix[i][1] : matrix[i][0];
        For(j, 0, n) {
            if (j != i) {
                a_elem = a_elem & matrix[i][j];
            }
        }
        a[i] = a_elem;
    }

    

    For(i, 0, n) {
        For(j, i+1, n) {
            if ((a[i] | a[j]) != matrix[i][j]) {
                
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

    For(i, 0, n) {
        cout << a[i] << " ";
    }

    cout << endl;
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
