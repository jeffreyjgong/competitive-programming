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

pair<vector<int>, int> minimizeSum(vector<int> nums) {
    priority_queue<pair<int, int>> maxHeap;

    for(int i = 0; i<nums.size(); i++) {
        maxHeap.push(make_pair(nums[i], i));
    }

    while (maxHeap.size() > 1) {
        pair<int, int> first_child = maxHeap.top();
        maxHeap.pop();
        pair<int, int> second_child = maxHeap.top();
        maxHeap.pop();

        if (first_child.first == 0 || second_child.first == 0) {
            maxHeap.push(first_child);
            maxHeap.push(second_child);
            break;
        }

        if (first_child.first > 0) first_child.first--;
        if (second_child.first > 0) second_child.first--;

        maxHeap.push(first_child);
        maxHeap.push(second_child);
    }

    int sum = 0;
    while (!maxHeap.empty()) {
        pair<int, int> p = maxHeap.top();
        nums[p.second] = p.first;
        sum += p.first;
        maxHeap.pop();
    }

    return make_pair(nums, sum);
}

// pairs, leftover
pair<int, int> dfs(int root, const unordered_map<int, vector<int>>& adj_list) {
    if (adj_list.find(root) == adj_list.end()) {
        return make_pair(0, 1);
    }

    int num_child_pairs = 0;
    vector<int> child_totals;
    vector<int> child_pairs;
    int total_things = 0;
    
    for(auto& child : adj_list.at(root)) {
        pair<int, int> result = dfs(child, adj_list);
        child_pairs.push_back(result.first);
        child_totals.push_back(result.first*2 + result.second);
        total_things += (result.first*2 + result.second);
    }

    pair<vector<int>, int> leftover = minimizeSum(child_totals);

    int pairs_so_far = (total_things - leftover.second)/2;

    int total_leftovers = 0;

    for(int i = 0; i<child_pairs.size(); i++) {
        int pairs_can_take = min(child_pairs[i], leftover.first[i]/2);
        pairs_so_far += pairs_can_take;
        total_leftovers += (leftover.first[i] - pairs_can_take*2);
    }

    pair<int, int> res = make_pair(pairs_so_far, total_leftovers + 1);

    return res;
}

void solve(){
    int n;
    input(n);

    unordered_map<int, vector<int>> adj_list;

    for(int i = 0; i<n-1; i++) {
        int superior;
        input(superior);

        adj_list[superior].push_back(i+2);
    }

    pair<int, int> result = dfs(1, adj_list);

    cout << result.first << endl;
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
