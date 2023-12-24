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
    int n, k, d;
    input(n,k,d);

    vector<int> a(n);
    arrPut(a);

    vector<int> b(k);
    arrPut(b);

    const int d_mod = k+1;
    int score = 0;

    unordered_map<int, int> away;

    For(i, 0, n) {
        // index i is place i+1
        away[abs((i+1) - a[i])]++;
    }

    int32_t num_can_add[2001] = {0};

    num_can_add[1] = k;
    For(i, 2, n+1) {
        For(j, 0, k) {
            if (b[j] >= i) {
                num_can_add[i]++;
            }
        }
    }

    if (d == 1) {
        cout << away[0] << endl;
        return;
    }

    unordered_map<int, int> days_away;
    days_away[abs(1 - a[0])] = abs(1 - a[0]);

    For(i, 1, n) {
        // i+1 is the real place
        int iterations = abs(i+1 - a[i]) / (num_can_add[i+1]);
        int remainder = abs(i+1 - a[i]) % num_can_add[i+1];

        if (iterations == 0 && remainder == 0) {
            days_away[0]++;
        } else if (remainder == 0) {
            int startstuff = k*(iterations-1);
            for(int j = k-1; j>=0; j--) {
                if (b[j] >= i+1) {
                    startstuff += (j+1);
                    break;
                }
            }
            days_away[startstuff]++;
        } else {
            int startstuff = k*iterations;
            int sofar = 0;
            for(int j = 0; j<k; j++) {
                if (b[j] >= i+1) {
                    sofar++;
                    if (sofar == remainder) {
                        startstuff+=(j+1);
                        break;
                    }
                }
            }

            days_away[startstuff]++;
        }
    }

    // bruh this is stupid as fuck why am i doing this
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
