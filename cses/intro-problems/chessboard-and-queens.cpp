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
typedef pair<int, int> pii;

int inline get1D(int r, int c) {
    return 8*r + c;
}

inline bool bitmaskClear(int index, int bitmask) {
    return (bitmask & (1 << index)) == 0;
}

inline void setBitmask(int index, int& bitmask) {
    bitmask = bitmask | (1 << index);
}

inline void unsetBitmask(int index, int& bitmask) {
    bitmask = bitmask & ~(1 << index);
}

inline int which45(int row, int col) {
    return 8 - (row - col);
}

inline int which135(int row, int col) {
    return row+col;
}

void solve(int& res, const bitset<64>& board, tuple<int, int, int>& flag_col_45_135, int row) {
    if (row == 8) {
        res++;
        return;
    }

    for(int col = 0; col < 8; col++) {
        if (board.test(get1D(row, col))) {
            continue;
        }
        if (
            bitmaskClear(col, get<0>(flag_col_45_135)) && 
            bitmaskClear(which45(row, col), get<1>(flag_col_45_135)) && 
            bitmaskClear(which135(row, col), get<2>(flag_col_45_135))
        ) {
            setBitmask(col, get<0>(flag_col_45_135)); setBitmask(which45(row, col), get<1>(flag_col_45_135)); setBitmask(which135(row, col), get<2>(flag_col_45_135));
            solve(res, board, flag_col_45_135, row+1);
            unsetBitmask(col, get<0>(flag_col_45_135)); unsetBitmask(which45(row, col), get<1>(flag_col_45_135)); unsetBitmask(which135(row, col), get<2>(flag_col_45_135));
        }
    }
}

int32_t main() {
    setup();

    bitset<64> board;

    int line = 0;
    while(line < 8) {
        string row;
        input(row);

        For(i, 0, 8) {
            if (row[i] == '*') {
                board.set(get1D(line, i));
            }
        }
        line++;
    }

    int res = 0;

    tuple<int, int, int> flag_col_45_135 = {0, 0, 0};
    solve(res, board, flag_col_45_135, 0);

    cout << res << endl;
    return 0;
}
