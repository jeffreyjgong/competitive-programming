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

    // one, two, three, four, five, six, seven, eight, nine
    // o t t f f s s e n
    // e o e r e x n t e
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
            } else if (inputLine[i] == 't') {
                // two
                if (inputLine.substr(i, 3) == "two") {
                    num += "2";
                    break;
                } 

                // three 
                else if (inputLine.substr(i, 5) == "three") {
                    num += "3";
                    break;
                }

            } else if (inputLine[i] == 's') {
                // six
                if (inputLine.substr(i, 3) == "six") {
                    num += "6";
                    break;
                }

                // seven
                if (inputLine.substr(i, 5) == "seven") {
                    num += "7";
                    break;
                }


            } else if (inputLine[i] == 'f') {
                // four
                if (inputLine.substr(i, 4) == "four") {
                    num += "4";
                    break;
                }

                // five
                else if (inputLine.substr(i, 4) == "five") {
                    num += "5";
                    break;
                }

            } else if (inputLine[i] == 'e') {
                // eight
                if (inputLine.substr(i, 5) == "eight") {
                    num += "8";
                    break;
                }

            } else if (inputLine[i] == 'o') {
                // one
                if (inputLine.substr(i, 3) == "one") {
                    num += "1";
                    break;
                }
            } else if (inputLine[i] == 'n') {
                // nine
                if (inputLine.substr(i, 4) == "nine") {
                    num += "9";
                    break;
                }
            }
        }

        for(int i = inputLine.length()-1; i>=0; i--) {
            if (isdigit(inputLine[i])) {
                num += inputLine[i];
                break;
            } else if (inputLine[i] == 'e') {
                // five
                if (i - 3 >= 0 && inputLine.substr(i-3, 4) == "five") {
                    num += "5";
                    break;
                }

                // nine
                else if (i - 3 >= 0 && inputLine.substr(i - 3, 4) == "nine") {
                    num += "9";
                    break;
                }
                // one
                
                else if (i - 2 >= 0 && inputLine.substr(i-2, 3) == "one") {
                    num += "1";
                    break;
                }
                // three
                else if (i - 4 >= 0 && inputLine.substr(i-4, 5) == "three") {
                    num += "3";
                    break;
                }

            } else if (inputLine[i] == 'r') {
                // four
                if (i - 3 >= 0 && inputLine.substr(i-3, 4) == "four") {
                    num += "4";
                    break;
                }

            } else if (inputLine[i] == 'x') {
                // six
                if (i - 2 >= 0 && inputLine.substr(i-2, 3) == "six") {
                    num += "6";
                    break;
                }

            } else if (inputLine[i] == 'n') {
                // seven
                if (i - 4 >= 0 && inputLine.substr(i-4, 5) == "seven") {
                    num += "7";
                    break;
                }

            } else if (inputLine[i] == 't') {
                // eight
                if (i - 4 >= 0 && inputLine.substr(i-4, 5) == "eight") {
                    num += "8";
                    break;
                }

            } else if (inputLine[i] == 'o') {
                // two
                if (i - 2 >= 0 && inputLine.substr(i-2, 3) == "two") {
                    num += "2";
                    break;
                }

            }
        }

        ans += stoll(num);
    }

    cout << ans << endl;
    return 0;
}
