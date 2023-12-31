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

    string s;
    input(s);

    int alph[26] = {0};

    For(i, 0, s.size()) {
        alph[s[i] - 'A']++;
    }

    int one = -1;
    int num_ones = 0;

    For(i, 0, 26) {
        if (alph[i] % 2 == 1) {
            num_ones++;
            one = i;
        }
    }

    if (num_ones > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string second_half = "";
    
    For(i, 0, 26) {
        if (alph[i] != 0) {
            second_half += string(alph[i]/2, (char) ('A' + i));
        }
    }

    string first_half = second_half;
    reverse(second_half.begin(), second_half.end());
    
    if (one != -1) {
        first_half += (char) ('A' + one);
    }

    first_half += second_half;
    cout << first_half << endl;
    return 0;
}
