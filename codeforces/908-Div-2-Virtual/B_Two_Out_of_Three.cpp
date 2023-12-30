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
    unordered_map<int, int> freq;

    int n;
    input(n);

    vector<int> a(n);
    arrPut(a);

    foreach(x, a) {
        if (freq.find(*x) != freq.end()) {
            freq[*x]++;
        } else {
            freq[*x] = 1;
        }
    }

    int multiples = 0;

    int key_with_more_than_two = -1;

    for(auto& it : freq) {
        if (it.second >= 2) {
            multiples++;
            if (multiples >= 2) {
                key_with_more_than_two = it.first;
                break;
            }
        }
    }

    if (multiples < 2) {
        cout << -1 << endl;
        return;
    }

    vector<int> output(n, 1);

    bool kmt_done = false;
    unordered_set<int> done;

    For(i, 0, n) {
        if (freq[a[i]] < 2) {
            output[i] = 1;
        } else if (a[i] == key_with_more_than_two) {
            if (kmt_done) {
                output[i] = 2;
            } else {
                output[i] = 1;
                kmt_done = true;
            }
        } else {
            if (done.count(a[i])) {
                output[i] = 3;
            } else {
                output[i] = 1;
                done.insert(a[i]);
            }
        }
    }

    foreach(x, output) {
        cout << *x << " ";
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
