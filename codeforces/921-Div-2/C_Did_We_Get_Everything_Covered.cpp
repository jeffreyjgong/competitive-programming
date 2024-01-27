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
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
typedef pair<int, int> pii;

int missing_from_chunk(int mask, int k) {
    for(int i = 0; i<k; i++) {
        if ((mask & (1 << i)) == 0) {
            return i;
        }
    }
    return -1;
}

int find_occurrence(const string& s, int start, char c) {
    if (start < 0) return -1;
    for(int i = start; i>=0; i--) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}

void solve(){
    int n, k, m;
    input(n, k, m);
    string s;
    input(s);

    int mask = 0;
    for(int i = 0; i<k; i++) {
        mask |= 1 << i;
    }

    int chunks = 0;
    int cur_chunk_mask = 0;

    for(int c = 0; c<m; c++) {
        cur_chunk_mask |= 1 << (s[c] - 'a');
        if (cur_chunk_mask == mask) {
            chunks++;
            cur_chunk_mask = 0;
        }
    }

    if (chunks >= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        // first do invalid
        string invalid = "";
        int cur_pointer = m-1;
        for(int i = 0; i<n-chunks-1; i++) {
            int last_a = find_occurrence(s, cur_pointer, 'a');
            if (last_a == -1) {
                cout << string(n, 'a') << endl;
                return;
            } else {
                cur_pointer = last_a - 1;
                invalid += 'a';
            }
        }

        if (cur_pointer < 0) {
            cout << string(n, 'a') << endl;
            return;
        }

        int remaining_steps = chunks + 1;
        while(remaining_steps) {
            int a_chunks = 0;
            int a_cur_chunk_mask = 0;

            for(int c = 0; c<=cur_pointer; c++) {
                a_cur_chunk_mask |= 1 << (s[c] - 'a');
                if (a_cur_chunk_mask == mask) {
                    a_chunks++;
                    a_cur_chunk_mask = 0;
                }
            }

            char last_missing = 'a' + missing_from_chunk(a_cur_chunk_mask, k);
            int last_occurrence = find_occurrence(s, cur_pointer, last_missing);
            if (last_occurrence == -1) {
                invalid += string(remaining_steps, last_missing);
                reverse(all(invalid));
                cout << invalid << endl;
                return;
            } else {
                invalid += last_missing;
                cur_pointer = last_occurrence - 1;
            }
            
            remaining_steps--;
        }
        reverse(all(invalid));
        cout << invalid << endl;
        return;
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
