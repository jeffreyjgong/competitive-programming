#include<bits/stdc++.h>

using namespace std;

// allows O(1) pop, push, and get minimum
template <typename T>
class MinStack {
    static_assert(is_same<decltype(declval<T>() < declval<T>()), bool>::value, "T must support operator<");
private:
    stack<pair<T, T>> st; // stack will store {element, minimum from this element and below}

public:
    // Push an element onto the stack
    void push(const T& value) {
        T new_min = this->st.empty() ? value : min(value, st.top().second);
        st.push(make_pair(value, new_min));
    }

    // Returns if the stack is empty
    bool empty() {
        return st.empty();
    }

    // Pop an element off the stack
    void pop() {
        st.pop();
    }

    // Get minimum
    T minimum() {
        return st.top().second;
    }
};

int main() {
    MinStack<int> ms;

    ms.push(5);
    cout << ms.minimum() << endl;

    ms.push(4);
    ms.push(3);
    ms.push(100);
    ms.push(2);

    cout << ms.minimum() << endl;
    ms.pop();

    cout << ms.minimum() << endl;
}