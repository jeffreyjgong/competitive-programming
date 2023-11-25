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
    int n, x;

    input(n);
    input(x);

    vector<int> a(n);
    vector<int> b(n);

    arrPut(a);
    arrPut(b);

    vector<pair<int, int>> a_index(n);

    for(int i = 0; i<n; i++) {
        a_index[i] = make_pair(a[i], i);
    }

    sort(a_index.rbegin(), a_index.rend());

    sort(b.begin(), b.end());

    vector<int> rearranged(n);

    int index = 0, check = 0;

    DFor(i, x-1, 0) {
        if (a_index[i].first > b[index]) {
            rearranged[a_index[i].second] = b[index];
            index++;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    index = n-1;

    For(i, x, n) {
        if (a_index[i].first > b[index]) {
            cout << "NO" << endl;
            return;
        } else {
            rearranged[a_index[i].second] = b[index];
            index--;
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i<rearranged.size(); i++) {
        cout << rearranged[i] << " ";
    }

    cout << endl;
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
