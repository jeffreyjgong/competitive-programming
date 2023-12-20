#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define D(x) cerr << #x " is " << (x) << endl
#define foreach(x, v) for (__typeof__ (v).begin() x=(v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define ss second

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int b_count = 0;

    foreach(c, s) {
        if (*c == 'B') ++b_count;
    }

    if (b_count == k) {
        cout << 0 << endl;
    } else if (b_count < k) {
        int a_count = 0;
        int cur = 0;
        while(a_count < k - b_count && cur < s.size()) {
            if (s[cur] == 'A') {
                a_count++;
            }
            cur++;
        }

        cout << 1 << endl;
        cout << cur << " " << 'B' << endl;
    } else {
        // b_count > k
        int a_count = 0;
        int cur = 0;
        while(a_count < b_count - k && cur < s.size()) {
            if (s[cur] == 'B') {
                a_count++;
            }
            cur++;
        }

        cout << 1 << endl;
        cout << cur << " " << 'A' << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
