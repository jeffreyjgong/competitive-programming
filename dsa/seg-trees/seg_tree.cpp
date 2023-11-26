#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    public:
        int size;
        vector<int> tree;

        // builds tree: O(N)
        SegmentTree(vector<int>& arr) {
            this->size = (int) arr.size();
            
            tree.resize(2*this->size);

            for(int i = 0; i<this->size; i++) {
                tree[this->size + i] = arr[i];
            }

            for(int i = this->size - 1; i > 0; --i) {
                tree[i] = tree[i << 1] + tree[i<<1 | 1];
            }

        }

        // updates the element at index p to the new value
        // O(log N)
        void update_node(int p, int value) {
            for(tree[p += this->size] = value; p>1; p>>=1) {
                tree[p>>1] = tree[p] + tree[p^1];
            }
        }

        // get sum on interval on [l,r)
        // O(log N)
        int query(int l, int r) {
            int res = 0;

            // loop to find the sum in range
            for(l += this->size, r += this->size; l<r; l >>= 1, r >>= 1) {
                if (l&1) {
                    res += tree[l++];
                }

                if (r&1) {
                    res += tree[--r];
                }
            }

            return res;
        }
};

int main() {
    vector<int> a;

    for(int i = 1; i<=12; i++) {
        a.push_back(i);
    }

    // a = [1,2,3,4,5,6,7,8,9,10,11,12]

    SegmentTree st(a);

    // 5
    cout << st.query(1,3) << endl;

    st.update_node(2, 1);

    // 3
    cout << st.query(1,3) << endl;
}
