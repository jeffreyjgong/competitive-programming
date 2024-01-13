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

int directions[] = {-1, 0, 1, 0, -1};
char direction_names[] = {'U', 'R', 'D', 'L'};

inline int to1D(int row, int col, int n) {
    return row*n + col;
}

inline bool is_valid(int n, int r, int c) {
    if (r < 0 || c < 0 || r>=n || c>=n) {
        return false;
    }
    return true;
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

bool unvisitedPartition(int n, int r, int c, int bitmask) {
    if (c == 0 && r != 0 && r != n-1) {
        if (bitmaskClear(to1D(r-1, c, n), bitmask) && bitmaskClear(to1D(r+1, c, n), bitmask)) {
            cout << "c0" << endl;
            return true;
        }
    } else if (r == 0 && c != 0 && c != n-1) {
        if (bitmaskClear(to1D(r, c-1, n), bitmask) && bitmaskClear(to1D(r, c+1, n), bitmask)) {
            cout << "r0" << endl;
            return true;
        }
    } else if (c == n-1 && r != 0 && r != n-1) {
        if (bitmaskClear(to1D(r-1, c, n), bitmask) && bitmaskClear(to1D(r+1, c, n), bitmask)) {
            cout << "cn" << endl;
            return true;
        }
    } else if (r == n-1 && c != 0 && c != n-1) {
        if (bitmaskClear(to1D(r, c-1, n), bitmask) && bitmaskClear(to1D(r, c+1, n), bitmask)) {
            cout << "rn" << endl;
            return true;
        }
    } else {
        return false;
    }
}

void solve(int& res, int& visited_bitmask, int r, int c, string& cur_moves, int n, int move) {
    if (r == n-1 && c == 0 && move == (n*n)-1) {
        cout << "valid" << endl;
        res++;
        return;
    }

    if (r == n-1 && c == 0) {
        cout << "too early" << endl;
        return;
    }

    if (move > n*n-1) {
        cout << "too many moves" << endl;
        return;
    }

    if (unvisitedPartition(n, r, c, visited_bitmask)) {
        cout << "partition" << endl;
        return;
    }

    For(i, 0, 4) {
        int new_r = r + directions[i];
        int new_c = c + directions[i+1];
        int new_1D = to1D(new_r, new_c, n);
        if (is_valid(n, new_r, new_c) && bitmaskClear(new_1D, visited_bitmask)) {
            setBitmask(new_1D, visited_bitmask);
            cur_moves[move] = direction_names[i];
            solve(res, visited_bitmask, new_r, new_c, cur_moves, n, move+1);
            cur_moves[move] = '?';
            unsetBitmask(new_1D, visited_bitmask);
        }
    }
}

int32_t main() {
    setup();

    int n;
    input(n);

    int visited_bitmask = 1;

    int res = 0;

    string cur_moves((n*n)-1, '?');

    solve(res, visited_bitmask, 0, 0, cur_moves, n, 0);

    cout << res << " solutions." << endl;

    return 0;
}
