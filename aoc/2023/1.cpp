#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using ll = long long;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    
}

int main() {
    setup();

    ifstream inputFile("../input-1.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return 1;
    }

    ll ans = 0;
    string inputLine;
    while(getline(inputFile, inputLine)) {
        if (inputLine.empty()) break;

        // process string
        string num = "";
        for(int i = 0; i<inputLine.length(); i++) {
            if (isdigit(inputLine[i])) {
                num += inputLine[i];
                break;
            }
        }

        for(int i = inputLine.length()-1; i>=0; i--) {
            if (isdigit(inputLine[i])) {
                num += inputLine[i];
                break;
            }
        }

        ans += stoll(num);
    }

    cout << ans << endl;
    return 0;
}
