#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>

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
#define int ll

int32_t main() {
    setup();

    vector<map<int, pair<int, int>, greater<int>>> src_dest_maps;

    vector<int> seeds;

    ifstream file("../input-5.txt");
    string line;

    // read seeds
    if (file.is_open()) {
        // read line from file
        while(getline(file, line)) {
            if (line.empty()) continue;
            istringstream iss(line);

            string header;

            iss >> header;

            if (header == "seeds:") {
                int number;
                while(iss >> number) {
                    seeds.push_back(number);
                }
            } else {
                map<int, pair<int, int>, greater<int>> src_dest_map;
                while(getline(file, line) && !line.empty()) {
                    istringstream inner_iss(line);
                    vector<int> row;
                    int number;
                    while(inner_iss >> number) {
                        row.push_back(number);
                    }

                    src_dest_map[row[1]] = make_pair(row[0], row[2]);
                }

                src_dest_maps.push_back(src_dest_map);
            }
        }

        int lowest_loc = __LONG_LONG_MAX__;

        foreach(s, seeds) {
            int src = *s;
            for(const auto & s_d_map : src_dest_maps) {
                auto it = s_d_map.lower_bound(src);

                if (it == s_d_map.end()) {
                    continue;
                }

                if (it->first + it->second.second - 1 >= src) {
                    src = (src-it->first) + it->second.first;
                }
            }

            lowest_loc = min(src, lowest_loc);
        }

        file.close();

        cout << "Lowest location: " << lowest_loc << endl;
    } else {
        cerr << "Can't open file!" << endl;
    }


}
