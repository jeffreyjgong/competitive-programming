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
    int n;
    input(n);

    // a
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeapA;

    for(int i = 0; i<n; i++) {
        int cur_elem;
        cin >> cur_elem;
        minHeapA.push(make_pair(cur_elem, i));
        if (minHeapA.size() > 3) {
            minHeapA.pop();
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeapB;

    for(int i = 0; i<n; i++) {
        int cur_elem;
        cin >> cur_elem;
        minHeapB.push(make_pair(cur_elem, i));
        if (minHeapB.size() > 3) {
            minHeapB.pop();
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeapC;

    for(int i = 0; i<n; i++) {
        int cur_elem;
        cin >> cur_elem;
        minHeapC.push(make_pair(cur_elem, i));
        if (minHeapC.size() > 3) {
            minHeapC.pop();
        }
    }

    vector<pair<int, int>> A;
    vector<pair<int, int>> B;
    vector<pair<int, int>> C;

    while(!minHeapA.empty()) {
        A.push_back(minHeapA.top());
        minHeapA.pop();
    }
    while(!minHeapB.empty()) {
        B.push_back(minHeapB.top());
        minHeapB.pop();
    }
    while(!minHeapC.empty()) {
        C.push_back(minHeapC.top());
        minHeapC.pop();
    }

    int max_score = INT_MIN;

    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            for(int k = 0; k<3; k++) {
                if (A[i].second == B[j].second || A[i].second == C[k].second || B[j].second == C[k].second) {
                    continue;
                }

                max_score = max(max_score, A[i].first + B[j].first + C[k].first);
            }
        }
    }

    cout << max_score << endl;
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
