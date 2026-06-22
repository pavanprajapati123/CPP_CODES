// Min Stack implementation using STL
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st, mn;

public:
    void push(int x) {
        st.push(x);

        if(mn.empty() || x <= mn.top())
            mn.push(x);
    }

    void pop() {
        if(st.top() == mn.top())
            mn.pop();

        st.pop();
    }

    int getMin() {
        return mn.top();
    }
};

int main() {
    MinStack s;

    s.push(5);
    s.push(2);
    s.push(8);

    cout << s.getMin();
}