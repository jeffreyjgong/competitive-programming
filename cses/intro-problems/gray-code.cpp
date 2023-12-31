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

    // n is 3 here
    // always starts from groups of 2^1 to 2^{n-1}
    // 000
    // 001
    // 011
    // 010
    // 110
    // 111
    // 101
    // 100

    // pattern is clearly take the first half, reverse it and append it and then add a leading 1 to it

    vector<string> gray_code = {"0", "1"};

    while(gray_code.size() < (size_t) pow(2, n)) {
        size_t start_len = gray_code.size();
        vector<string> reverse_gray(start_len);
        reverse_copy(gray_code.begin(), gray_code.end(), reverse_gray.begin());

        gray_code.insert(gray_code.end(), reverse_gray.begin(), reverse_gray.end());

        For(i, 0, start_len) {
            gray_code[i] += "0";
        }
        For(i, start_len, gray_code.size()) {
            gray_code[i] += "1";
        }
    }

    foreach(x, gray_code) {
        cout << *x << endl;
    }


    return 0;
}
