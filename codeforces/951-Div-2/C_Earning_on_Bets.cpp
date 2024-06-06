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

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to compute the LCM of an array of integers
int lcmArray(const std::vector<int>& nums) {
    if (nums.empty()) return 0; // Return 0 if the array is empty
    
    int result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = lcm(result, nums[i]);
    }
    return result;
}

void solve(){
    int n;
    input(n);

    vector<int> k(n);
    arrPut(k);

    int lcm = lcmArray(k);
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += lcm/k[i];
    }

    if (sum < lcm) {
        
        // lcm *= 2;
        vector<int> x(n);
        for(int i = 0; i<n; i++) {
            x[i] = lcm/k[i];
        }
        arrPrint(x);
    } else {
        cout << -1 << endl;
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
