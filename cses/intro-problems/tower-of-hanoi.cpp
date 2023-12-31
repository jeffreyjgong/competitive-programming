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

// ideal way to move all disks is to
// move n-1 disks to an auxiliary tower, then
// move the nth disk to the R tower, then move n-1 disks to
// the R tower. This can obviously be done recursively

// to move 1 disk it takes 1 move, to move 2 disks it takes (1 move + 1 + 1 move) = 3
// to move 3 disks it takes (2 moves + 1 + 2 moves) = 7
// to move 4 disks it takes (3 moves + 1 + 3 moves) = 15
// to move 5 disks it takes (4 moves + 1 + 4 moves) = 31
// a_n = 2*a_n-1 + 1
// a_2 = 2*a_1 + 1
// a_3 = 2*(2*a_1 + 1) + 1 = 2^2a_1 + 2^1 + 1
// a_4 = 2*(2*(2*a_1+1) + 1) + 1 = 2^3a_1 + 2^2 + 2^1 + 2^0
// thus pattern is easy to see it is simply = 2^n-1

inline void move(int source_tower, int destination_tower) {
    cout << source_tower << " " << destination_tower << endl;
}

void hanoi(int num_disks, int source_tower, int destination_tower, int auxiliary_tower) {
    if (num_disks == 1) {
        move(source_tower, destination_tower);
        return;
    }

    // start the move of n-1 disks to middle tower
    hanoi(num_disks-1, source_tower, auxiliary_tower, destination_tower);

    // move the biggest disk to the right
    move(source_tower, destination_tower);

    // move n-1 disks to right tower
    hanoi(num_disks-1, auxiliary_tower, destination_tower, source_tower);
}

int32_t main() {
    setup();

    int disks;
    input(disks);

    cout << pow(2, disks) - 1 << endl;

    hanoi(disks, 1, 3, 2);
    return 0;
}
