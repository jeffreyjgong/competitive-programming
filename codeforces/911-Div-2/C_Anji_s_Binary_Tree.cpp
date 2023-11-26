#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
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
#define int ll
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int topdown(unordered_map<int, pair<int, int>>& adj_list, string& s, int root, unordered_map<int, int>& memo) {
    if (root == -1) return -1;

    if (adj_list[root].first == -1 && adj_list[root].second == -1) {
        return 0;
    }

    // if (memo.find(root) != memo.end()) {
    //     return memo[root];
    // }

    int left = topdown(adj_list, s, adj_list[root].first, memo);
    int right = topdown(adj_list, s, adj_list[root].second, memo);
    int minimum;
    if (left == -1) {
        if (s[root] == 'U') {
            // memo[root] = 1 + right;
            minimum = 1 + right;
        } else if (s[root] == 'L') {
            // memo[root] = 1 + right;
            minimum = 1 + right;
        } else {
            // memo[root] = right;
            minimum = right;
        }
    } else if (right == -1) {
        if (s[root] == 'U') {
            // memo[root] = 1 + left;
            minimum = 1 + left;
        } else if (s[root] == 'L') {
            // memo[root] = left;
            minimum = left;
        } else {
            // memo[root] = 1 + left;
            minimum = 1 + left;
        }
    } else {
        if (s[root] == 'U') {
            // memo[root] = 1 + min(left, right);
            minimum = 1 + min(left, right);
        } else if (s[root] == 'L') {
            // memo[root] = min(left, 1 + right);
            minimum = min(left, 1 + right);
        } else {
            // memo[root] = min(1 + left, right);
            minimum = min(1 + left, right);
        }
    }

    // return memo[root];
    return minimum;
}

void solve(){
    int n;
    input(n);

    string s;
    input(s);

    unordered_map<int, pair<int, int>> adj_list;

    unordered_map<int, int> memo;

    for(int i = 0; i<n; i++) {
        int l, r;
        input(l, r);
        adj_list[i] = make_pair(l-1, r-1);
    }

    // for(const auto & i : adj_list) {
    //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    // }

    cout << topdown(adj_list, s, 0, memo) << endl;
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
