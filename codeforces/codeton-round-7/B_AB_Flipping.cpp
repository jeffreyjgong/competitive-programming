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

void solve(){
    int n;
    input(n);

    string s;
    input(s);
    int total = 0;

    bool found_a = false;
    bool found_b = false;
    int first_a = -1;
    int first_b = -1;
    for(int i = n-1; i>=0; i--) {
        if (s[i] == 'A') {
            found_a = true;
            first_a = i;
        } else if (s[i] == 'B') {
            found_b = true;
        }
    }

    if (!found_b) {
        cout << total << endl;
        return;
    } else if (!found_a) {
        cout << total << endl;
        return;
    }

    found_a = false;
    for(int i = 0; i<n; i++) {
        if (s[i] == 'A') {
            found_a = true;
        } else if (s[i] == 'B') {
            if (found_a) {
                first_b = i;
                break;
            }
        }
    }

    if (first_b == -1) {
        cout << total << endl;
        return;
    }

    int cur_as = 0;
    for(int i = first_a; i<n; i++) {
        if (s[i] == 'A') {
            cur_as++;
        } else if (s[i] == 'B') {
            if (i == first_b) {
                total += cur_as;
            } else {
                total += 1 + cur_as;
            }

            cur_as = 0;
        }
    }

    cout << total << endl;
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
